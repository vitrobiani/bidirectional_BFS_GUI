#include "BFS.h"
bool runBFS = false;

void RestorePath(Cell* pc) {
	while (pc != nullptr)
	{
		maze[pc->getRow()][pc->getCol()] = PATH;
		pc = pc->getParent();
	}
}

bool CheckNeighbor(int row, int col, Cell* pCurrent, int toCheck, int toMark, queue<Cell*>& q, queue<Cell*> opp_q) {
	if (maze[row][col] == toCheck) {
		runBFS = false; 
		cout << "The solution has been found. \n";
		printf("on row: %d \t col: %d", row, col);
		RestorePath(pCurrent);



		Cell* y = opp_q.front();
		while (!opp_q.empty()) {
			if (y->getRow() == row && y->getCol() == col) {
				break;
			}
			opp_q.pop();
			y = opp_q.front();
		}
		RestorePath(y);



		return false;
	}
	else // maze[row][col] must be SPACE (WHITE)
	{
		Cell* pc = new Cell(row, col, pCurrent);
		maze[row][col] = toMark;
		q.push(pc);
		return true;
	}
}

void RunBFSIteration(queue<Cell*>& q, int colour, queue<Cell*>& opp_q) {
	Cell* pCurrent;
	int row, col;
	bool go_on = true;

	if (q.empty())
	{
		runBFS = false;
		cout << "There is no solution. Grays is empty\n";
		return;
	}
	else // grays is not empty
	{
		pCurrent = q.front();
		q.pop(); // extract the first element from grays
		// 1. paint pCurrent black
		row = pCurrent->getRow();
		col = pCurrent->getCol();
		if (maze[row][col] != START)
			maze[row][col] = BLACK;
		// 2. check all the neighbors of pCurrent
		// go up
		int opposite_colour = (colour == GRAY) ? YELLOW : GRAY;
		if (maze[row + 1][col] == SPACE || maze[row + 1][col] == opposite_colour) 
			go_on = CheckNeighbor(row + 1, col, pCurrent, opposite_colour, colour, q, opp_q);
		// down
		if(go_on && (maze[row - 1][col] == SPACE || maze[row - 1][col] == opposite_colour))
			go_on = CheckNeighbor(row - 1, col, pCurrent, opposite_colour, colour, q, opp_q);
		// left
		if (go_on && (maze[row ][col- 1] == SPACE || maze[row ][col- 1] == opposite_colour))
			go_on = CheckNeighbor(row , col- 1, pCurrent, opposite_colour, colour, q, opp_q);
		// right
		if (go_on && (maze[row][col +1] == SPACE || maze[row][col + 1] == opposite_colour))
			go_on = CheckNeighbor(row, col + 1, pCurrent, opposite_colour, colour, q, opp_q);
		
	}
}

//void RunBFSIteration2() {
//	Cell* pCurrent;
//	int row, col;
//	bool go_on = true;
//
//	if (yellows.empty())
//	{
//		runBFS = false;
//		cout << "There is no solution. Yellows is empty\n";
//		return;
//	}
//	else // yellows is not empty
//	{
//		pCurrent = yellows.front();
//		yellows.pop(); // extract the first element from grays
//		// 1. paint pCurrent black
//		row = pCurrent->getRow();
//		col = pCurrent->getCol();
//		if (maze[row][col] != START)
//			maze[row][col] = YELLOW;
//		// 2. check all the neighbors of pCurrent
//		// go up
//		if (maze[row + 1][col] == SPACE || maze[row + 1][col] == BLACK)
//			go_on = CheckNeighbor2(row + 1, col, pCurrent);
//		// down
//		if(go_on && (maze[row - 1][col] == SPACE || maze[row - 1][col] == BLACK))
//			go_on = CheckNeighbor2(row - 1, col, pCurrent);
//		// left
//		if (go_on && (maze[row ][col- 1] == SPACE || maze[row ][col- 1] == BLACK))
//			go_on = CheckNeighbor2(row , col- 1, pCurrent);
//		// right
//		if (go_on && (maze[row][col +1] == SPACE || maze[row][col + 1] == BLACK))
//			go_on = CheckNeighbor2(row, col + 1, pCurrent);
//		
//	}
//}
//
//bool CheckNeighbor2(int row, int col, Cell* pCurrent) {
//	if (maze[row][col] == BLACK)
//	{
//		runBFS = false;
//		cout << "The solution has been found. \n";
//		printf("on row: %d \t col: %d", row, col);
//		RestorePath(pCurrent);
//		return false;
//	}
//	else // maze[row][col] must be SPACE (WHITE)
//	{
//		Cell* pc = new Cell(row, col, pCurrent);
//		maze[row][col] = YELLOW;
//		yellows.push(pc);
//		return true;
//	}
//}
