#include "Demmon.h"

void Demon::CreateDemon() {
    srand(time(NULL));
    Player pPl = Player();
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (DemonBody[i] != 0) {
            j++;
        }
    }
    if (j == 100) {
        return;
    }
    else {
        for (int i = 0; i < 100; i++) {
            if (DemonBody[i] == 0) {
                while (true) {
                    DemonPosition[i][0] = (rand() % 13) + 1;
                    DemonPosition[i][1] = (rand() % 13) + 1;
                    if (!(pPl.plx == DemonPosition[i][0] && pPl.ply == DemonPosition[i][1])) {
                        break;
                    }
                }
                textcolor(4);
                gotoxy(2 * DemonPosition[i][0], DemonPosition[i][1]);
                std::cout << "*";
                textcolor(15);
                DemonBody[i] = 1;
                break;
            }
        }
    }
}
void Demon::LoadDemon() {
    for (int i = 0; i < 100; i++) {
        if (DemonBody[i] == 1) {
            textcolor(4);
            gotoxy(2 * DemonPosition[i][0], DemonPosition[i][1]);
            std::cout << "*";
            textcolor(15);
        }
    }
}
void Demon::MoveDemon() {
    Player pPl = Player();
    for (int i = 0; i < 100; i++) {
        //1
        if (DemonPosition[i][0] > pPl.plx && DemonPosition[i][1] > pPl.ply) {
            int a = (int)((DemonPosition[i][1] - pPl.ply) / (DemonPosition[i][0] - pPl.plx));
            DemonPosition[i][0]--;
            DemonPosition[i][1] += a / 5;
        }
        //4
        else if (DemonPosition[i][0] > pPl.plx && DemonPosition[i][1] < pPl.ply) {
            int a = (int)((DemonPosition[i][1] - pPl.ply) / (DemonPosition[i][0] - pPl.plx));
            DemonPosition[i][0]--;
            DemonPosition[i][1] -= a / 5;
        }
        //2
        else if (DemonPosition[i][0] < pPl.plx && DemonPosition[i][1] > pPl.ply) {
            int a = (int)((DemonPosition[i][1] - pPl.ply) / (DemonPosition[i][0] - pPl.plx));
            DemonPosition[i][0]++;
            DemonPosition[i][1] += a / 5;
        }
        //3
        else if (DemonPosition[i][0] < pPl.plx && DemonPosition[i][1] < pPl.ply) {
            int a = (int)((DemonPosition[i][1] - pPl.ply) / (DemonPosition[i][0] - pPl.plx));
            DemonPosition[i][0]++;
            DemonPosition[i][1] -= a / 5;
        }
        else if (DemonPosition[i][0] == pPl.plx && DemonPosition[i][1] > pPl.ply) {
            DemonPosition[i][1]++;
        }
        else if (DemonPosition[i][0] == pPl.plx && DemonPosition[i][1] < pPl.ply) {
            DemonPosition[i][1]--;
        }
        else if (DemonPosition[i][0] < pPl.plx && DemonPosition[i][1] == pPl.ply) {
            DemonPosition[i][0]++;
        }
        else if (DemonPosition[i][0] > pPl.plx && DemonPosition[i][1] == pPl.ply) {
            DemonPosition[i][0]--;
        }
        else {

        }
    }
}
void Demon::DelDemon() {
        for (int i = 0; i < 100; i++) {
            if (DemonPosition[i][0] == 0 || DemonPosition[i][0] == 14 || DemonPosition[i][1] == 0 || DemonPosition[i][1] == 14) {
                DemonBody[i] = 0;
            }
        }
}
int DemonPosition[100][2];
int DemonBody[100];