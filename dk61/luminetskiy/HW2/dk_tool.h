#ifndef dk_tool.h
#define  dk_tool.h


//count square
float Square (Circle *aCircle)


//circle size
typedef struct Circle
{
    int x;
    int y;
    int rad;
}circle;

//circle options
typedef struct List
{
    circle *sizeCircle;
    int size;
    int current_size;
} FigList;


FigList *createCircle(int size);
//deleting
void destroyFigure(FigList *aFigList);

//interface
int addToFigure(FigList *aFigList, int x, int y, int rad);

void print(FigList *aFigList);

//count square
float Square (circle *aCircle);


#endif //dk_tool_h
