//���� ������

/*
############�ϴ� ���� �ͺ��� �����############
���� ���� �ٰ��� �� ĳ���ʹ� ���� ���ϴ� ������ ���� ���̴�.
ĳ���ʹ� w,a,s,dŰ�� �����̸�, pŰ�� ���� �����Ѵ�.
*/

/*
############���� ���############
Ư�� Ȯ���� ����ź��, Ư�� Ȯ���� 
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
