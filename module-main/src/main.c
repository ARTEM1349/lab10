

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "lib.h"

int main(int argc, char *argv[]) 
{
    int a, i,b;
    long int  d[]= {24,342,345,234,545,678};
    long int  *t;
    unsigned int s = 6; 
    char *c;
    
    srand((unsigned int)time(NULL));
    a = rand() % 10;
    lab05(a);
    
    if(argc > 1)
    {
      s = 0;
      for(i = 1; i < argc; i++)
      {
      	s++;
      }
      
      
      t = (long int*) malloc (s * sizeof(long int));
      for(i = 1, b = 0; i < argc; i++, b++)
      {
      	 t[b] = strtol(argv[i], &c, 10);
      }
            
      lab06(t,s);
      
    }
    else
    {  
      lab06(d,s);     
    }
    
    return 0;
}
