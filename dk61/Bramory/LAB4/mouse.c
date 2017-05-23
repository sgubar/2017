#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#include "List.h"
#include "mouse.h"
#include "draw.h"

#define CELL_WIDTH  (width/N)
#define CELL_HEIGHT (height/N)
int N;
int width;
int height;
int x;
int y;

IntList *aList;


void MousePressed(int button, int state, int x, int y)
{
    bool down = false;
    if (state == down )
    {
        system("cls");
        int indexToDelete = (N * (int)(y/CELL_HEIGHT) + (int)(x/CELL_WIDTH +1)) - 1;
//        printf("IndexToDelete = %d\n", indexToDelete);
//        printf("CELL_HEIGHT = %d\n", CELL_HEIGHT);
//        printf("CELL_WIDTH = %d\n", CELL_WIDTH);
//        printf("Y = %d, (%d/%d) = (%d)\n",y, y, CELL_HEIGHT, (int) y/CELL_HEIGHT);
//        printf("X = %d, (%d/%d) = (%d)\n",x, x, CELL_WIDTH, (int) x/CELL_WIDTH);
//        printf("\nCoordinate = %i\n\n", indexToDelete+1);
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                glutSetWindowTitle("LeftButtonPressed");
                MarkIndexToDelete(aList, indexToDelete, 1);

                break;

            case GLUT_MIDDLE_BUTTON:
                glutSetWindowTitle("MiddleButtonPressed");

                if (0 != DeleteMarksElements(aList) )
                    DeleteIntValueAtIndex(aList, indexToDelete);
                break;

            case GLUT_RIGHT_BUTTON:
                glutSetWindowTitle("RightButtonPressed");
                MarkIndexToDelete(aList, indexToDelete, 0);

                break;
        }
        //printf("IndexToMark = %d\n", indexToDelete);
    }
}

void mouse(int button, int state, int ax, int ay)
{
    x = ax;
    y = ay;
    //down = state == GLUT_LEFT_BUTTON;
}

void motion(int ax, int ay)
{
    x = ax;
    y = ay;
}

void MouseMove(int ax, int ay)
{
    glutSetWindowTitle("MouseMove");
    x = ax;
    y = ay;
}


void MousePressedMove(int ax, int ay)
{
    glutSetWindowTitle("MousePressedMove");
}






