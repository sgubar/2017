#ifndef dk_tool_h
#define dk_tool_h

void enter_values(int *Arzmr, int *Atypetest, int *Atypevalues, int *Atypeval_similar, int *Atypeval_false);
void array_values_full_random(int *array, int rzmr);
void array_values_typeval_similar(int *array, int rzmr, int typeval_similar);
void array_values_opposite_order(int *array, int rzmr);
void array_values_typeval_false(int *array, int rzmr, int typeval_false);
void array_fill_values(int *array, int rzmr, int typevalues, int typeval_similar, int typeval_false);
void array_sort_choose(int *array, int rzmr, int typetest);

#endif 
