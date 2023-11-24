#include "Demmon.h"

void Player::initialization() {
    srand(time(NULL));
    Structure pSt = Structure();
    plx = (rand() % 13) + 1;
    ply = (rand() % 13) + 1;
    pSt.StructureLoad();
    gotoxy(2 * plx, 2 * ply);
    std::cout << "*";
}
void Player::LoadPlayer() {
    Structure pSt = Structure();
    Demon pDm = Demon();
        if (_kbhit()) {
            int key = _getch();
            switch (key) {
            case Kw: ply--; break;
            case Ka: plx--; break;
            case Ks: plx++; break;
            case Kd: ply++; break;
            }
            if (plx == 0) {
                plx++;
            }
            if (plx == 14) {
                plx--;
            }
            if (ply == 0) {
                ply++;
            }
            if (ply == 14) {
                ply--;
            }
            system("cls");
            pSt.StructureLoad();
            pDm.LoadDemon();
            gotoxy(2 * plx, ply);
            std::cout << "*";
        }
        else {
            gotoxy(2 * plx, ply);
            std::cout << "*";
        }
}