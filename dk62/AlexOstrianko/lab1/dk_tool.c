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
	int Pointer;
	char a[5];
	do{		
		Pointer = 0;
		scanf("%s",a);	
		int i;
		for (i=0;a[i]!='\0';i++)
		{
			if('0' > a[i] || a[i] > '9' )
				Pointer = 1;
		}
	}while(Pointer==1);
	*Inp = atoi(a); 
}
