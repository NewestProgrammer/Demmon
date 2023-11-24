#include "Demmon.h"

void Structure::StructureLoad() {
    char StructureArr[15][15];
    for (int Arri = 0; Arri < 15; Arri++) {
        for (int Arrj = 0; Arrj < 15; Arrj++) {
            if (Arrj == 0 || Arrj == 14 || Arri == 0 || Arri == 14)
                StructureArr[Arrj][Arri] = { '1' };
            else
                StructureArr[Arrj][Arri] = { ' ' };
        }
    }
        for (int Arri = 0; Arri < 15; Arri++) {
            for (int Arrj = 0; Arrj < 15; Arrj++) {
                gotoxy(2 * Arrj, Arri);
                std::cout << StructureArr[Arrj][Arri];
            }
        }
}