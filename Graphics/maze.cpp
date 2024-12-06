#include "maze.h";
int maze[MSZ][MSZ] = {0};
int START_ROW1 = generateRandomInt(0, MSZ - 1);
int START_COL1 = generateRandomInt(0, MSZ - 1);
int START_ROW2 = generateRandomInt(0, MSZ - 1);
int START_COL2 = generateRandomInt(0, MSZ - 1);


void SetupMaze() {
	int i, j;
	// outer margins
	for (i = 0;i < MSZ;i++)
	{
		maze[0][i] = WALL; // first line
		maze[MSZ-1][i] = WALL; // last line
		maze[i][0] = WALL; // left column
		maze[i][MSZ-1] = WALL; // left column
	}

	// inner space
	for(i=1;i<MSZ-1;i++)
		for (j = 1;j < MSZ-1;j++)
		{
			if (i % 2 == 1) // mostly spaces
			{
				if (rand() % 10 > 2) // 80%
					maze[i][j] = SPACE;
				else
					maze[i][j] = WALL;
			}
			else // mostly walls
			{
				if (rand() % 10 >= 6) // 60%
					maze[i][j] = WALL;
				else
					maze[i][j] = SPACE;

			}
		}

	maze[START_ROW1][START_COL1] = START;
	maze[START_ROW2][START_COL2] = START;

}

void ShowMaze()
{
	int i, j;

	for(i=0;i<MSZ;i++)
		for (j = 0;j < MSZ;j++)
		{
			//1. set color of cell
			switch (maze[i][j])
			{
			case SPACE:
				glColor3d(1, 1, 1); // white
				break;
			case WALL:
				glColor3d(0, 0, 0); // black
				break;
			case START:
				//glColor3d(0.6, 0.6, 1); // blue
				glColor3d(1, 0, 0); // red
				break;
			case TARGET:
				glColor3d(1, 0, 0); // red
				break;
			case PATH:
				glColor3d(1, 0.4 , 1); // magenta
				break;
			case GRAY:
				glColor3d(0, 1, 0); // green
				break;
			case YELLOW:
				glColor3d(1, 1, 0); // yellow
				break;
			case BLACK:
				glColor3d(0.6, 0.6, 0.6); // gray
				break;
			}
			// show cell
			glBegin(GL_POLYGON);
			glVertex2d(j, i);
			glVertex2d(j, i + 1);
			glVertex2d(j+1, i + 1);
			glVertex2d(j + 1, i );
			glEnd();
		}
}
