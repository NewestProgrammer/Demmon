#include "Demmon.h"

void gameover() {
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM,1,8000,8000,1,8,0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

    char buffer[8000 * 24];

    int bpm = 128; // BPM ����
    int note_duration = wfx.nSamplesPerSec * (60.0 / bpm) / 4; // ��ǥ ���� ��� (4����ǥ ����)

    int sequence[] = { 1 ,2 ,4 ,2 ,6 ,0,0,6,0,0 ,5,5,5,5,5,5,1 ,2 ,4 ,2 ,5 ,0,0,5,0,0 ,4,4,4,4,4,4 };
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        int note_index = (t / note_duration) % sizeof(sequence);
        double freq;

        switch (sequence[note_index]) {
        case 1: // ��
            freq = 440.00;
            break;
        case 2: // ��
            freq = 493.88;
            break;
        case 3: // ��#
            freq = 554.37;
            break;
        case 4: // ��
            freq = 587.33;
            break;
        case 5: // ��
            freq = 659.26;
            break;
        case 6:
            freq = 740.00;
            break;
        case 0:
            freq = 0.00;
            break;
        default: // ��ǥ
            freq = 0.00;
            break;
        }

        buffer[t] = static_cast<char>(sin(2 * M_PI * freq * t / wfx.nSamplesPerSec) * 127);
    }

    WAVEHDR hdr = { buffer,sizeof(buffer), };

    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));

    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));

    Sleep(8000); // ��� �ð��� �����Ͽ� ���ϴ� ���̸�ŭ �Ҹ��� ����մϴ�.

    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));

    waveOutClose(hwo);
}