#include <stdio.h>
#include <stdlib.h>      //when rendom function use <stdlib.h>
int linear(int a[], int x)
{
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    int a[10], i, x, b;
    for (i = 0; i < 10; i++)
    {
        a[i] = rand() % 50;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nenter search element = ");
    scanf("%d", &x);

    b = linear(a, x);
    if (b > 0)
    {
        printf("search element found %d position ",b);
    }
    else
    {
        printf("element is not found...");
    }
}