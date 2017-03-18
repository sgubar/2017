double stepen(double InpA, double Step){
	double i;//dlya forov	
	double InputKoef=InpA;
	if (Step==0)
		InpA=1;
	if(Step>0){
		for(i=1;i<Step;i++){
			InpA=InpA*InputKoef;			
		}
	}
	if(Step<0){
		for(i=-1;i>Step;i--){
			InpA=InpA*InputKoef;
		}
		InpA=1/InpA;
	}	
	return InpA;			
}
double sum(double InpA){	
	double i;//dlya forov
	double summa=0;
	if(InpA<0)
	{
		for(i=0;i>InpA;i--){
			summa = summa + stepen(2,i);
		}
	}else{
		for(i=0;i<InpA;i++){
			summa = summa + stepen(2,i);
		}
	}
	return summa;
}
double Abs(double InpC){
	if(InpC<0)
		InpC= InpC*-1;
	return InpC;	
}
void vvod (double *Inp){
  	char character;
	int Pointer = 0;
  	char Str[5];
  	do{
  		int Current = 0;
  		Pointer = 0;
	  	while ((character = getchar()) != '\n')
	  	{	
		  	if(Current<4){		
		    Str[Current]=character;
			if((Str[Current]<'0'||Str[Current]>'9')&&Str[Current]!='-')
				Pointer = 1;
			Current++;}
	  	}  
	  	Str[Current]='\0';
	  	if(Pointer!=0)	  		
			printf("Try again: ");
	}while(Pointer != 0);
    putchar ('\n'); 
  	*Inp=atoi(Str);//perevod v chislo
}
