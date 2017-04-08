#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cor_types.h"

char gchar()
{
while(true)
	{
	char* line = gstring();
	if(line == NULL)
		return CHAR_MAX;
	char c1, c2;
	if(sscanf(line, " %c %c", &c1, &c2) == 1)
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

//-----------------------------------------------------------------------------------------------------------
/*
double gdouble()
{
while(true)
	{
	char* line = gstring();
	if(line == NULL)
		return 1;

	double d;
	char c;
	if(sscanf(line, " %lf %c", &d, &c) == 1)
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
*/
//-----------------------------------------------------------------------------------------------------------
/*
float gfloat()
{
while(true)
	{
	char* line = gstring();
	if(line == NULL)
		return 1;
	char c;
	float f;
	if(sscanf(line, " %f %c", &f, &c) == 1)
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
*/
//-----------------------------------------------------------------------------------------------------------

int gint()
{
while(true)
    {
	char* line = gstring();
	if(line == NULL)
        return INT_MAX;
    int n;
	char c;
    if(sscanf(line, " %d %c", &n, &c) == 1)
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

//-----------------------------------------------------------------------------------------------------------

long long glonglong()
{
while(true)
    {
    char* line = gstring();
    if(line == NULL)
        return LLONG_MAX;
    long long n;
	char c;
    if(sscanf(line, " %lld %c", &n, &c) == 1)
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

//-----------------------------------------------------------------------------------------------------------

char *gstring()
{
char* buf = NULL;
unsigned int cp = 0;
unsigned int n = 0;
int c;

while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
	if(n + 1 > cp)
    	{
        if(cp == 0)
            cp = 32;
        else if(cp <= (UINT_MAX / 2))
            cp *= 2;
        else
            {
            free(buf);
            return NULL;
            }
        char* tmp = realloc(buf, cp * sizeof(char));
        if(tmp == NULL)
            {
            free(buf);
            return NULL;
            }
        buf = tmp;
    	}
    buf[n++] = c;
    }
if(n == 0 && c == EOF)
    return NULL;
char* min = malloc((n + 1) * sizeof(char));
strncpy(min, buf, n);
free(buf);
min[n] = '\0';
return min;
free(min);
}

//-----------------------------------------------------------------------------------------------------------

