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

const int START_ROW1 = 25;
const int START_COL1 = 25;
const int START_ROW2 = 75;
const int START_COL2 = 75;

extern int maze[MSZ][MSZ];

extern bool runBFS;

extern queue <Cell*> grays;
extern queue <Cell*> yellows;

#endif //def
