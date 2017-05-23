#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "draw.h"


void Drawing(int x, int y, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
