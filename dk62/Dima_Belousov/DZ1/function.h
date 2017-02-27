#ifndef function_h
#define function_h


void result(int N, int matr1[N][N],int matr2[N][N]){

int result_matr[N][N];
int i,j,k;

for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
result_matr[i][j] = 0;
for(k = 0; k < N; k++){
result_matr[i][j] += matr1[i][k] * matr2[k][j];


}

}
}
for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
printf("%i ", result_matr[i][j]);
}
printf("\n");
}

}
#endif
