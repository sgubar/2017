#ifndef dk_tool_h
#define dk_tool_h

void enter_values(int *Aarray_size, int *Atypetest, int *Atypevalues, int *Atypeval_similar, int *Atypeval_false, int *Atypesearch, int *Atypelin_arr, int *Avalue);
void array_values_full_random(int *array, int array_size);
void array_values_typeval_similar(int *array, int array_size, int typeval_similar);
void array_values_opposite_order(int *array, int array_size);
void array_values_typeval_false(int *array, int array_size, int typeval_false);
void array_fill_values(int *array, int array_size, int typevalues, int typeval_similar, int typeval_false);
void array_sort(FILE *file, int *array, int *sec_array, int array_size, int typetest, int typevalues, int typeval_similar, int typeval_false);
void array_search(FILE *file, int *array, int *sec_array, int array_size, int typesearch, int typelin_arr, int value);

#endif 
