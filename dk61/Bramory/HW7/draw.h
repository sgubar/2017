#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

void renderBitmapString(float x, float y, void *font, char *string);
// root - left - right
void DrawTree(TreeNode *aNode, int direct, void(*func)(TreeNode *, int) );
void drawTreeNode(TreeNode *aNode, int direct );
void drawTreeLine(TreeNode *aNode, int direct);

#endif // DRAW_H_INCLUDED
