
/*
Return number what we type / ignore another symbols.  
*/
int num_scan( void );

/*
Numbers which contain matrix -> transp_matrix 
*/
void transp(int x, int y, int transp_matr[y][x], int matr[x][y]);

/*
Get the numbers of matrix 
*/
void read_matr(int x, int y, int matr[x][y] );

/*
Show numbers of matrix on the screen 
*/
void print_matr(int x, int y, int matr[x][y]);

#endif


