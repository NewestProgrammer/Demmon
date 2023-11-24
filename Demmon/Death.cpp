#include "Demmon.h"

void DetermineDeath() {
	Player pPl=Player();
	Demon pDm = Demon();
	for (int i = 0; i <100; i++) {
		if (DemonPosition[i][0] == pPl.plx && DemonPosition[i][1] == pPl.ply&&DemonBody[i]==1) {
			gameover();
			ExitProcess(0);
		}
	}
}