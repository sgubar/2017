#include "dk_tool.h"
#include <stdio.h>
#include <string.h>

int Search(char TheString[], char TheWord[])
{
	int PositionW = 0;
	int PositionStr = 0;
	int Coordinates = -1;
	int Counter = 0;
	
	while(PositionStr < strlen(TheString))
	{																	
			for(int n = 0; n < strlen(TheWord); n++)
			{																			
				if(TheWord[PositionW+n] == TheString[PositionStr+n]) 
				{
				Counter++;							//счётчик совпадений																//ñ÷¸ò÷èê ñîâïàäåíèé ñèìâîëîâ
					if(Counter == strlen(TheWord))
					{
						Coordinates = PositionStr+1;
						return Coordinates;										
					}					
				}				
			}	
			Counter = 0;
			PositionStr++;
	}
	
	if(Coordinates = -1)								       //если совпадений не найдено																//åñëè ñîâïàäåíèé íåò
 	{
 		return -1;
	}
}


