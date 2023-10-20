// self referntial linklist  node
#include <stdio.h>
struct self
{
    int data;
    char c;
    struct self *ptr;
};
int main()
{
    struct self a, b, c;

    a.data = 65;
    a.c = 'A';
    a.ptr = NULL;

    b.data = 66;
    b.c = 'B';
    b.ptr = NULL;

    c.data = 67;
    c.c = 'C';
    c.ptr = NULL;

    // printf("A = value of data : %d\t ch : %c", a.data, a.c);
    // printf("\nB = value of data : %d\t ch : %c", b.data, b.c);

    // a.ptr = &b;
    // b.ptr = &a;
    c.ptr = &a;

    printf("\nc = value of data : %d\t ch : %c", c.ptr->data, c.ptr->c);
}