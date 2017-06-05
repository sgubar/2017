#ifndef dk_tool_h
#define dk_tool_h

typedef struct element
{
	char value;
	struct element *left;
	struct element *right;
}Core;

typedef struct aTree
{
	int count;
	Core *root;
}Tree;

Tree *createTree();
Core *createCore(char val);

void destroyTree(Tree *aTree);
void destroyCore(Core *aCore);

Core *findParent(Tree *aTree, char val);
int insertElement(Tree *aTree, char val);
void deleteElement(Tree *aTree, Core *aCore);
void deleteValueElement(Tree *aTree, char val);

Core *minVal(Core *aCore);
Core *search(Core *aCore, char val);

void printTree(Core *aCore);
void print(Tree *aTree);

void fillElements(Tree *aTree);
void deleteRootElement(Tree *aTree);
void createNotSameElement(Tree *aTree);
void searchRandomChar(Tree *aTree);

#endif
