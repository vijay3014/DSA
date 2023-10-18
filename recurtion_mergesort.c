// merge sort => [D & C] => divide & conqar
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int b[50];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void main()
{
    int a[15], n = 15, i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 99 + 1;
    }
    printf("Before Sorting array:-\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("\nAfter sorting array:-\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}