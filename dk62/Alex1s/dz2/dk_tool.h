#ifndef dk_tool_h
#define dk_tool_h

typedef struct Afigure
{
	float *x_coor;
	float *y_coor;
}Figure;

typedef struct Atriangles
{
	Figure *place;
	int current_fig;
	int max_fig;
	float area[5];
}Triangles;

void make_triangle(Triangles *Element, Figure *Dots);
void enter_coor(Figure *Dots);
void delete_triangle(Triangles *Element, Figure *Dots, int i);
void delete_all(Triangles *Element, Figure *Dots);
float calc_area(Figure *Dots);

#endif
