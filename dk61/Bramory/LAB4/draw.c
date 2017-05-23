#include <GL/glut.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List.h"

#define CELL_WIDTH  (width/N)
#define CELL_HEIGHT (height/N)
int N;
int width;
int height;

void renderBitmapString(float x, float y, void *font, char *string)
{
  char *c;
  int aLength = strlen(string);
  int i;
  for (i = 0; i < aLength; i++)
  {
        x -= 4; //for every digit
  }
  glRasterPos2f(x, y);
  for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void drawCell(int x, int y, IntNode *aNode )
{
    switch(aNode->mark)
    {
        //non-chosen
        case false:
        glColor3f(1, 1, 0);
        break;

        //chosen cells
        case true:
        glColor3f(0, 0.6, 1);
        break;
    }

     //Print All numbers
    glBegin(GL_QUAD_STRIP);
    glVertex2f( x    * CELL_WIDTH +1, y    * CELL_HEIGHT);
    glVertex2f((x+1) * CELL_WIDTH, y    * CELL_HEIGHT);
    glVertex2f( x    * CELL_WIDTH +1,(y+1) * CELL_HEIGHT - 1);
    glVertex2f((x+1) * CELL_WIDTH,(y+1) * CELL_HEIGHT - 1);
    glEnd();
    glColor3f(0, 0, 0);

    char *string = (char*)malloc(sizeof(char)*10);
    itoa (aNode->value, string, 10);
    renderBitmapString((x * CELL_WIDTH  + CELL_WIDTH /2 - 1),
                       (y * CELL_HEIGHT + CELL_HEIGHT/2 + 4),
                       GLUT_BITMAP_9_BY_15, string);
    free(string);
}


/*
void timer(int)
{
    //glutPostRedisplay();
    display();
  //glutTimerFunc(500, timer, 0);
}
*/
