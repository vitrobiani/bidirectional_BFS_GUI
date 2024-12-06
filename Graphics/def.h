#pragma once
#ifndef DEF
#define DEF

#include "Cell.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include <iostream>
#include <queue>
#include <random>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;

const int MSZ = 100;

const int SPACE = 0;
const int WALL = 1;
const int START = 2;
const int TARGET = 3;
const int PATH = 4;
const int GRAY = 5;
const int YELLOW = 6;
const int BLACK = 7;

extern int START_ROW1;
extern int START_COL1;
extern int START_ROW2;
extern int START_COL2;

extern int maze[MSZ][MSZ];

extern bool runBFS;

extern queue <Cell*> grays;
extern queue <Cell*> yellows;


inline int generateRandomInt(int min, int max) {
    static std::random_device rd;      // Random device
    static std::mt19937 gen(rd());     // Mersenne Twister engine
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

#endif //def
