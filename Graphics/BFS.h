#pragma once
#ifndef BFS
#define BFS

#include "def.h"

void RestorePath(Cell* pc);

bool CheckNeighbor(int row, int col, Cell* pCurrent, int toCheck, int toMark, queue<Cell*>& q, queue<Cell*> opp_q);

void RunBFSIteration(queue<Cell*>& q, int colour, queue<Cell*>& opp_q);

//void RunBFSIteration2();
//
//bool CheckNeighbor2(int row, int col, Cell* pCurrent);

#endif // !BNF
