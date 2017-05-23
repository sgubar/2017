#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

void mouse(int button, int state, int ax, int ay);
void motion(int ax, int ay);
void MouseMove(int ax, int ay);
void MousePressed(int button, int state, int x, int y);
void MousePressedMove(int ax, int ay);


#endif // MOUSE_H_INCLUDED
