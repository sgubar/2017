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
void delete_fig(Triangles *Element, Figure *Dots, int i);
float calc_area(Triangles *Element, Figure *Dots);
void print_structs(Triangles *Element, Figure *Dots);
void print_struct(Triangles *Element, Figure *Dots, int i);
void shellsort(Triangles *Element, Figure *Dots);
int line_search(Triangles *Element, Figure *Dots, float Val);
void appropriation(Triangles *Element, Figure *Dots, int i, int H);
void save(Triangles *Element, Figure *Dots, float *tmp, float *tmp_x, float *tmp_y);
void boot(Triangles *Element, Figure *Dots, float *tmp, float *tmp_x, float *tmp_y);

#endif
