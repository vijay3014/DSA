#include<stdio.h>
#include<stdlib.h>
#define n 10


int bubble_short(int a[])
{
    int i , j ,t ;
    for(i = 0 ; i < n ; i++)
    {
        for(j=i+1 ; j < n ;j++)
        {
           if(a[i] > a[j])
           {
               t = a[i];
               a[i] = a[j];
               a[j] = t;
           }
        }
    }
}

int main()
{
    int a[n] , i;
     for ( i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
   
    for ( i = 0; i < n; i++)
    {
        printf("%d ,",a[i]);
    }
   
   bubble_short(a);

    printf("\nShort Array Is : ");
    for(i = 0 ; i < n; i++)
    {
        printf("%d ,",a[i]);
    }
}