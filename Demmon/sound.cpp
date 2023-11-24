#include "Demmon.h"

void gameover() {
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM,1,8000,8000,1,8,0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

    char buffer[8000 * 24];

    int bpm = 128; // BPM 설정
    int note_duration = wfx.nSamplesPerSec * (60.0 / bpm) / 4; // 음표 길이 계산 (4분음표 기준)

    int sequence[] = { 1 ,2 ,4 ,2 ,6 ,0,0,6,0,0 ,5,5,5,5,5,5,1 ,2 ,4 ,2 ,5 ,0,0,5,0,0 ,4,4,4,4,4,4 };
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        int note_index = (t / note_duration) % sizeof(sequence);
        double freq;

        switch (sequence[note_index]) {
        case 1: // 라
            freq = 440.00;
            break;
        case 2: // 시
            freq = 493.88;
            break;
        case 3: // 도#
            freq = 554.37;
            break;
        case 4: // 레
            freq = 587.33;
            break;
        case 5: // 미
            freq = 659.26;
            break;
        case 6:
            freq = 740.00;
            break;
        case 0:
            freq = 0.00;
            break;
        default: // 쉼표
            freq = 0.00;
            break;
        }

        buffer[t] = static_cast<char>(sin(2 * M_PI * freq * t / wfx.nSamplesPerSec) * 127);
    }

    WAVEHDR hdr = { buffer,sizeof(buffer), };

    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));

    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));

    Sleep(8000); // 재생 시간을 조정하여 원하는 길이만큼 소리를 재생합니다.

    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));

    waveOutClose(hwo);
}