// binary => sorted => acending/decending
#include <stdio.h>
int binarysearch(int a[], int x, int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == x)
        {
            return mid + 1;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {2, 4, 6, 8, 11, 15, 18, 21, 25, 28, 30, 33, 35, 38, 40}, x, b;
    int n = sizeof(a) / sizeof(a[0]);
    printf("array size = %d\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nenter search element = ");
    scanf("%d", &x);

    b = binarysearch(a, x, n);
    if (b < 0)
    {
        printf("element is not found...");
    }
    else
    {
        printf("search element found %d position ", b);
    }
}