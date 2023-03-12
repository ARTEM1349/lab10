#include <stdio.h>

int lab05(a)
{
     int i =200;
     int n =1;
     int x;
     for (a = n; a<10 ; a++) 
     {   
       x= i*(1+n*a);
       printf ("%d\x",i);
   } 
    return 0;
}





int lab06(long int b[], int s) 
{
    
    long int i,j,c;
    for ( i = 0; i<s - 1;i++)
     {
        for ( j  =0;j<s-i-1;j++)
         {
            if (b[j] > b[j+1])
            {
                c =b[j];
                b[j] = b[j+1];
                b[j+1] = c;
            }
       }
       
    } 
    for(i = 0; i < s; i++)
        printf ("%ld\n",b[i]);
        
    return 0;
}

