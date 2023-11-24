//게임 구성도

/*
############일단 쉬운 것부터 만든다############
적이 점점 다가올 떄 캐릭터는 적을 피하는 게임을 만들 것이다.
캐릭터는 w,a,s,d키로 움직이며, p키로 적을 공격한다.
*/

/*
############공격 방법############
특정 확률로 유도탄을, 특정 확률로 
*/

#include "Demmon.h"

//################################
/*
'w': 119
's': 115
'a': 97
'd': 100
*/
//################################
int main() {
    srand(time(NULL));
    textcolor(15);
    Demon Dm = Demon();
    Player Pl = Player();
    Structure St = Structure();
    for (int i = 100; i < 100; i++) {
        DemonBody[i] = 0;
    }
    Pl.initialization();
    double CreateDemonTime = clock();
    double MoveDemonTime = clock();
    while (true) {
        system("cls");
        St.StructureLoad();
        Pl.LoadPlayer();
        if (clock() - CreateDemonTime >= (double)5000) {
            Dm.CreateDemon();
            CreateDemonTime = clock();
        }
        if (clock() - MoveDemonTime >= (double)1000) {
            Dm.MoveDemon();
            CreateDemonTime = clock();
        }
        Dm.LoadDemon();
        Dm.DelDemon();

        DetermineDeath();
        Sleep(60);
    }
    return 0;
}
//################################
