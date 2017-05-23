#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "List.h"
#include "keyboard.h"


int N;
int width;
int height;
int MIN_VALUE;
int MAX_VALUE;
IntList *aList;

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'e':
        exit(0);
        break;
    }
}

void SKeyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        DeleteIntValueAtIndex(aList, 0);
        break;

    case GLUT_KEY_RIGHT:
        if (aList->count < N*N)
            AddIntValueToList(aList, randomIntFromRange(MIN_VALUE, MAX_VALUE));
        break;

    case GLUT_KEY_UP:
        while (aList->count < N*N)
            AddIntValueToList(aList, randomIntFromRange(MIN_VALUE, MAX_VALUE));
        break;

    case GLUT_KEY_DOWN:
        while (aList->count > 0)
            DeleteIntValueAtIndex(aList, 0);
        break;
    }
}
