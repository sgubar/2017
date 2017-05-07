#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#include "cor_types.h"

char gch(void)
{
while(true)
	{
	char *line = (char *) malloc(sizeof(char));
	gstring(line);
	
	if(!line)
		return CHAR_MAX;
	
	char c1, c2;
	if(sscanf(line, "%c %c", &c1, &c2) == 1)
		{
		free(line);
		return c1;
		}
	else
		{
		free(line);
		printf("Retry: ");
		}
	}
}

//-------------------------------------------------------------------------

double gdbl()
{
while(true)
	{
	char *line = (char *) malloc(sizeof(char));
	gstring(line);
	
	if(!line)
		return DBL_MAX;
	
	double d;
	char c;
	if(sscanf(line, "%lf %c", &d, &c) == 1)
		{
		free(line);
		return d;
		}
    else
    	{
		free(line);
		printf("Retry: ");
		}
	}
}

//-------------------------------------------------------------------------

float gflt(void)
{
while(true)
	{
	char *line = (char *) malloc(sizeof(char));
	gstring(line);
	
	if(!line)
		return FLT_MAX;
	
	char c;
	float f;
	if(sscanf(line, "%f %c", &f, &c) == 1)
        {
		free(line);
		return f;
		}
	else
		{
		free(line);
		printf("Retry: ");
        }
    }
}

//-------------------------------------------------------------------------

int gint(void)
{
while(true)
    {
	char *line = (char *) malloc(sizeof(char));
	gstring(line);
	
	if(!line)
        return INT_MAX;
    
	int n;
	char c;
    if(sscanf(line, "%i %c", &n, &c) == 1)
    	{
        free(line);
        return n;
        }
    else
        {
        free(line);
		printf("Retry: ");
        }
    }
}

//-------------------------------------------------------------------------

long long gllong(void)
{
while(true)
    {
    char *line = (char *) malloc(sizeof(char));
	gstring(line);
	
    if(!line)
        return LLONG_MAX;
    
	char c;
	long long n;
    if(sscanf(line, "%ll %c", &n, &c) == 1)
        {
        free(line);
        return n;
        }
    else
        {
        free(line);
        printf("Retry: ");
        }
    }
}

//-------------------------------------------------------------------------

void gstring(char *min)
{
char *buf = NULL;
unsigned int cp = 0, n = 0;
int c;

while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
	if(n + 1 > cp)
    	{
        if(!cp)
            cp = 32;
        
        else if(cp <= UINT_MAX)		//2^32
            cp += 32;
			
        else
            {
            free(buf);
            return;
            }
        char *tmp = realloc(buf, sizeof(char) * cp);
        if(!tmp)
			{
			free(buf);
			return;
			}
		buf = tmp;
        tmp = NULL;
		}
	buf[n++] = c;
    }
if(!n && c == EOF)
    return;
char *lll = realloc(min, sizeof(char) * (n + 1));
if(!lll)
	{
	free(buf);
	free(min);
	return;        
	}
min = lll;
lll = NULL;

strncpy(min, buf, n);
free(buf);

min[n] = '\0';
}

//-------------------------------------------------------------------------

