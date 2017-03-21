#ifndef dk_tool_h 
#define dk_tool_h 

typedef struct koordinates 
{ 
	float x_koordunatu; 
	float y_koordunatu; 
	float radius; 
}koordunatu; 

koordunatu *paranetru(); 

float proverka(); 

void enter(koordunatu *AA); 

float calculate(koordunatu *AAA); 

#endif
