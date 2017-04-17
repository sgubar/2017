void sorting_Choice(char line[], int counter) 
{ 
int  min; 
for( int i=0; i<counter-1; i++) 
{
	min = i; 
	for(int k=i+1; k<counter; k++) 
		{ 
			if(line[k]<line[min]) 
				{ 
					min=k; 
				} 
		}
	int tmp=line[i]; 
	line[i]=line[min]; 
	line[min]=tmp; 
} 
} 

void sorting_Bubble(char line[], int counter) 
{ 
for(int i =counter - 1; i>1; i--) 
{ 
for(int k = 0; k<i; k++) 
{ 
if(line[k]>line[k+1]) 
{ 
int tmp = line[k]; 
line[k]=line[k+1]; 
line[k+1]=tmp; 
} 
} 
} 
} 

void sorting_Inserts(char line[], int counter) 
{ 
for(int i =1; i<counter; i++) 
{ 
int tmp=line[i]; 
int k=i; 
while(k>0 && line[k-1]>=tmp) 
{ 
line[k]=line[k-1]; 
k--; 
} 
line [k]=tmp; 

} 
}
