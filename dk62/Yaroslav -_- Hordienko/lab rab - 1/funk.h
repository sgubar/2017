#ifndef funk_h
#define funk_h


struct ABCQ
{
	int A;
	int B;
	int C;
	float Q;
	float F;
} rivnyannya;

float syma (float a, float b);
void result (struct ABCQ *p);
float dilennya (float a, float b);
int faktorial (int e);
int stepin (int a, int b);
int kvadrat (int a);
void enter_peremennye (struct ABCQ *p);

#endif
