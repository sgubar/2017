//**********************************
// Visualization of Binary Tree
//**********************************
//
//Created by Bramory 18.05.17
//

#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "binary_tree.h"
#include "draw.h"
#include "List.h"
#include "keyboard.h"
#include "mouse.h"

#include "const.c"

void Initialize ()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //draw lines, nodes, values
    DrawTree(aTree->root, 0, drawTreeLine);
    DrawTree(aTree->root, 0, drawTreeNode);
    //in the left up corner show coordinates
    Show_XY_pos(x,y);
    glutSwapBuffers();
}



void MyIdle()
{
    display();
    Sleep(sleep);
    //glutSetWindowTitle("NothingToBeDone");
}

void MousePressed(int button, int state, int x, int y)
{
    bool down = false;
    LinkNode *aLinkNode = aList->head;
    TreeNode *aChosenTreeNode;
    if (state == down )
    {
        system("cls");
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                //glutSetWindowTitle("LeftButtonPressed");
                aChosenTreeNode = MarkNodeToDelete(aTree, aList, x, y);
                analysis( aChosenTreeNode );
                printf("\n\naList to delete:\n");
                PrintList(aList);

                break;

            case GLUT_MIDDLE_BUTTON:
                //glutSetWindowTitle("MiddleButtonPressed");
                    destroyIntTree(aTree);
                    aTree = getIntTreeWithRandValues(1, 0);

                printf("You get a New Binary Tree!");


            //delete all chosen TreeNodes
            case GLUT_RIGHT_BUTTON:
                //glutSetWindowTitle("RightButtonPressed");
                 while(aList->count >= 1)
                {
                    deleteNodeWithValue(aTree, aLinkNode->value);
                    aLinkNode = aLinkNode->next;
                    DeleteIntValueAtIndex(aList, 0);
                }
                printf("\naTree->count = %d", aTree->count);
                break;

                break;
        }
    }
}


void MouseMove(int ax, int ay)
{
    x = ax;
    y = ay;
    //glutSetWindowTitle("MouseMove");
//    printf("X = %d\n", x);
//    printf("Y = %d\n", y);
}


void MousePressedMove(int ax, int ay)
{
    x = ax;
    y = ay;
    //glutSetWindowTitle("MousePressedMove");
}

void Keyboard(unsigned char key, int x, int y)
{
    system("cls");
    printf("aTree with a count (%d)\n", aTree->count);

    switch (key)
    {

        case '1':
            printf("Straight method:\n");
            printTree(aTree, straight);
            break;

        case '2':
            printf("Symmetry method:\n");
            printTree(aTree, symmetry);
            break;

        case '3':
            printf("Backward method:\n");
            printTree(aTree, backward);
            break;

        case 'e':
            exit(0);
            break;
    }
}

void SKeyboard(int key, int x, int y)
{
    system("cls");
    TreeNode *aNodeToDelete = NULL;

    switch (key)
    {
        case GLUT_KEY_LEFT:

           //delete left child of the root
            aNodeToDelete = aTree->root->leftChild;
            if (aTree->count > 1 && aNodeToDelete != NULL )
            {
                deleteNodeWithValue(aTree, aNodeToDelete->value);
                printf("Root->leftChild was deleted!");
            }
            else
            {
                printf("Root->leftChild don't exist!");
            }

            break;

        case GLUT_KEY_RIGHT:

            //delete right child of the root
            aNodeToDelete = aTree->root->rightChild;
            if (aTree->count > 1 && aNodeToDelete != NULL )
            {
                deleteNodeWithValue(aTree, aNodeToDelete->value);
                printf("Root->rightChild was deleted!");
            }
            else
            {
                printf("Root->rightChild don't exist!");
            }

            break;

        case GLUT_KEY_UP:

            //filling aTree with amount == const
            //initialization in the const.c
            while (aTree->count < amount)
            {
                insertIntValueToTree(aTree, randomIntFromRange(min, max));
            }
            printf("aTree have MAX_AMOUNT");

            break;

        case GLUT_KEY_DOWN:

             //insert 1 Node
            if (aTree->count < amount)
            {
                while ( 1 )
                {
                    if (0 == insertIntValueToTree(aTree, randomIntFromRange(min, max)))
                    {
                        printf("a TreeNode was inserted!");
                        break;
                    }
                }
            }
            else
            {
                printf("aTree have MAX_AMOUNT");
            }
            break;
    }
    printf("\naTree->count = %d", aTree->count);
}

void timer(int a)
{
    glutPostRedisplay();
    glutTimerFunc(500, timer, 0);
}

void Reshape(int new_width, int new_height)
{
  glViewport(0, 0, new_width, new_height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, height, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);

 width = new_width;
 height = new_height;
}

int main(int argc, char **argv)
{
    srand(time(0));
    aTree = getIntTreeWithRandValues(amount, 0);
    aList = CreateIntList();

    //Initialization
    glutInit(&argc, argv);
    width = glutGet(GLUT_SCREEN_WIDTH);
    height = glutGet(GLUT_SCREEN_HEIGHT) * 0.91;
    printf("w = %d, h = %d", width, height);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_position, y_position);
    glutCreateWindow("Binary_Tree");

    //Registration
    glutDisplayFunc(display);
    Initialize();
    glutTimerFunc(500, timer, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    glutIdleFunc(MyIdle);
    glutMouseFunc(MousePressed);
    glutPassiveMotionFunc(MouseMove);
    glutMotionFunc(MousePressedMove);
    glutReshapeFunc(Reshape);

    glutMainLoop();

    destroyIntTree(aTree);
    DestroyIntList(aList);
    return 0;
}


// root - left - right
void DrawTree(TreeNode *aNode, int direct, void(*func)(TreeNode *, int) )
{
	func(aNode, direct);

	if(aNode->leftChild != NULL)
    {
        DrawTree(aNode->leftChild, -1, func );
    }
    //give left up point of the figure
	if(aNode->rightChild != NULL)
    {
        DrawTree(aNode->rightChild, 1, func );
    }
}


void drawTreeLine(TreeNode *aNode, int direct)
{
    //Levels for visualizing == 6
    if (aNode->level > MAX_DEPTH || NULL == aNode)
        return;

    int x = getNodePos_X(aTree, aNode);
    int y = getNodePos_Y(aTree, aNode);

    //tree lines
    if (direct == -1 || direct == 1)
    {
        glColor3f(1, 0, 0);
        glBegin(GL_LINES);
        // move from the left up corner
        // to point in the center of the current element
        glVertex2f( x + SizeOfSquare/2, y + SizeOfSquare/2);

        // draw line in the center of the previous element
        glVertex2f( x - (width/(2 << aNode->level ))*direct + SizeOfSquare/2, y-deltaY + SizeOfSquare/2 );
        glEnd();
    }
}

void drawTreeNode(TreeNode *aNode, int direct )
{
    //Levels for visualizing == 6
    if (aNode->level > MAX_DEPTH || NULL == aNode)
        return;

    int x = getNodePos_X(aTree, aNode);
    int y = getNodePos_Y(aTree, aNode);

    //Print Shape
    if (aNode->mark == 1)
        glColor3f(0.1, 0.1, 0.8); //marked
    else
        glColor3f(1, 1, 0); //non-marked

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+SizeOfSquare, y);
    glVertex2f(x+SizeOfSquare, y+SizeOfSquare);
    glVertex2f(x, y + SizeOfSquare);
    glEnd();

//    Print Information (digits)
    char *string = (char*)malloc(sizeof(char)*10);

    itoa (aNode->value, string, 10);
    glColor3f(0, 0, 0);
    renderBitmapString(x + SizeOfSquare/2 - 1,
                       y + SizeOfSquare/2 + 4,
                       GLUT_BITMAP_9_BY_15,
                       string);
    free(string);
}

void renderBitmapString(float x, float y, void *font, char *string)
{
  char *c;
  int aLength = strlen(string);
  for (int i = 0; i < aLength; i++)
  {
        x -= 4; //for every digit
  }

  glRasterPos2f(x, y);
  for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}






//int x_now = 0;
//int y_now = 0;

//void animateNode (TreeNode *aNode, int direct)
//{
//    if (NULL != aNode);
//        return;
//
//    Levels for visualizing == 6
//    if (aNode->level > 5 || NULL == aNode)
//        return;
//
//    int x_begin = getNodePos_X(aTree, aNode);
//    int y_begin = height/3 + aNode->level * deltaY;
//
//    int x_end = x - (width/(2 << aNode->level ))*direct + SizeOfSquare/2;
//    int y_end = y-deltaY + SizeOfSquare/2;
//
//    int x_now = x_begin;
//    int y_now = y_begin;
//
//    while(x_now != x_end)
//    {
//
//
//        if (direct == 1 || direct == -1)
//        {
//            glBegin(GL_LINES);
//            glColor3f(1, 0, 0);
//             move from the left up corner
//             to point in the center of the current element
//            glVertex2f( x_now, y_now);
//
//             draw line in the center of the previous element
//            glVertex2f( x_now , y_now );
//            glEnd();
//        }
//                        Print Shape
//            if (aNode->mark == 1)
//                glColor3f(0.1, 0.1, 0.9); //marked
//            else
//                glColor3f(1, 1, 0); //non-marked
//
//            glBegin(GL_QUADS);
//                glVertex2f(x_now, y_now);
//                glVertex2f(x_now+SizeOfSquare, y_now);
//                glVertex2f(x_now+SizeOfSquare, y_now+SizeOfSquare);
//                glVertex2f(x_now, y_now + SizeOfSquare);
//            glEnd();
//
//        x_now < x_end
//            ? x_now++
//            : x_now--;
//
//        y_now < y_end
//            ? y_now++
//            : y_now--;
//
//        Sleep(50);
//    }
//
//}
//
//
