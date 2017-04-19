#ifndef dk_tool_h
#define dk_tool_h

typedef struct Afigure
{
	float x_coor[3];
	float y_coor[3];
	float area;
}Figure;

typedef struct Atriangles
{
	Figure *place;
	int current_fig;
	int max_fig;
}Triangles;

void make_triangle(Triangles *Element, Figure *Dots);
void enter_coor(Triangles *Element, Figure *Dots);
void delete_all(Triangles *Element, Figure *Dots);
float calc_area(Triangles *Element, Figure *Dots);

#endif
