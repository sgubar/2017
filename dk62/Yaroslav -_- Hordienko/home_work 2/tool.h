#ifndef tool_h
#define tool_h


 typedef struct charkolo {
 	int x;
 	int y;
 	int radius;
 }kolo;

typedef struct charfigure{
	kolo * kolo1;

}figure;

float ploscha (figure *acharfigure){
	int t=0;
	printf ("Enter radius\n");
	scanf("%i", &t);
	acharfigure->kolo1->radius = t;
	int r = acharfigure->kolo1->radius;
	int S = r*r*(3,14);
	return S;
}


//float ploscha (figure *acharfigure);


#endif
