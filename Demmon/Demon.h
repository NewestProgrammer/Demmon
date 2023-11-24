#pragma once

class Demon {
public:
    void CreateDemon();
    void MoveDemon();
    void DelDemon();
    void LoadDemon();
};
#ifndef SHARED_DEMON_INFO
#define SHARED_DEMON_INFO
extern int DemonPosition[100][2];
extern int DemonBody[100];
#endif
