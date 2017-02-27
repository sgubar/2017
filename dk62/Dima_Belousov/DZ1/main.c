int main(int argc, char *argv[])
{
int N;
int i,j;
int x = 1;

printf("Vvedte razmer matr \n");
scanf("%i", &N);

int matr1[N][N];
int matr2[N][N];





for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
printf("Vvedite %i element matr1: \n", x);
scanf("%i", &matr1[i][j]);
x++;
}
}

x = 1;

for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
printf("Vvedite %i element matr2: \n", x);
scanf("%i", &matr2[i][j]);
x++;
}
}

result(N,matr1,matr2);

}
