#include "maze.h"
#include "BFS.h"

queue <Cell*> grays;
queue <Cell*> yellows;

void init()
{
	glClearColor(0.5, 0.5, 0.5, 0);// color of window background
	glOrtho(0, MSZ, 0, MSZ, -1, 1); // set the coordinates system

	srand(time(0));

	SetupMaze();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer

	ShowMaze();

	glutSwapBuffers(); // show all
}

void idle() 
{
	if (runBFS) {
		RunBFSIteration(grays, GRAY, yellows);
	}
	if (runBFS) {
		RunBFSIteration(yellows, YELLOW, grays);
	}
		
	glutPostRedisplay(); // indirect call to display
}

void menu(int choice) {
	switch (choice)
	{
	case 1: // BFS
		Cell * pc = new Cell(START_ROW1, START_COL1, nullptr);
		grays.push(pc);
		Cell * pc2 = new Cell(START_ROW2, START_COL2, nullptr);
		yellows.push(pc2);

		runBFS = true;
		break;
	}
}

int main(int argc, char* argv[]) 
{

	srand(time(0));

	printf("%d \t %d\n", START_ROW1, START_COL1);
	printf("%d \t %d\n", START_ROW2, START_COL2);


	glutInit(&argc, argv);
	// definitions for visual memory (Frame buffer) and double buffer
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(600, 20);
	glutCreateWindow("BFS");

	// display is a refresh function
	glutDisplayFunc(display);
	// idle is a update function
	glutIdleFunc(idle);
	// add menu
	glutCreateMenu(menu);
	glutAddMenuEntry("BFS", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	init();

	glutMainLoop();
	return 0;
}