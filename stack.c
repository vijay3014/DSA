#include<stdio.h>
#define n 5
int a[n],top =-1;
int insertend(int data)
{
    if(top>=n-1)
    {
        printf("stack is overflow\n");

    }
    else
    {
        top++;
        a[top]=data;
    }
}
int display()
{
    for(int i=0;i<top;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    insertend(100);
    insertend(200);
    insertend
}