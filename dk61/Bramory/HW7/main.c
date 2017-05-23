//**********************************
// EUCLID_SIEVE
//**********************************
//
//Created by Bramory 18.05.17
//

#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "List.h"
#include "keyboard.h"
#include "draw.h"
#include "mouse.h"

#include "const.c"


void Initialize ()
{
    glClearColor(1, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    int i;
    for (i = 1; i < N; ++i) //vertical
    {
        glVertex2f(i * CELL_WIDTH, 0);
        glVertex2f(i * CELL_WIDTH,  height);
    }
    for (i = 1; i < N; ++i) //vertical
    {
        glVertex2f(0, i * CELL_HEIGHT);
        glVertex2f(width, i * CELL_HEIGHT);
    }
    glEnd();

    //NUMBERS
    int amount = 0;
    IntNode *aNode = aList->head;
    int y,x;
        for (y = 0; y < N; y++)
        {
             for (x = 0; x < N; x++)
            {
                if(amount < aList->count)
                {
                    drawCell(x, y , aNode);
                    aNode = aNode->next;
                    amount++;
                }
            }
        }
    glutSwapBuffers();
}

void MyIdle()
{
    display();
    Sleep(sleep);
}

int main(int argc, char **argv)
{
    srand(time(0));

    aList = getIntListWithRandValues(N*N, 1);

    //Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    width = glutGet(GLUT_SCREEN_WIDTH);
    height = glutGet(GLUT_SCREEN_HEIGHT) * 0.91;
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_position, y_position);
    glutCreateWindow("Euclid_Sieve");

    //Registration
    glutDisplayFunc(display);
    Initialize();
    //glutTimerFunc(500, timer, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    glutIdleFunc(MyIdle);
    glutMouseFunc(MousePressed);
    glutPassiveMotionFunc(MouseMove);
    glutMotionFunc(MousePressedMove);
    glutMainLoop();

    DestroyIntList(aList);
    return 0;
}
