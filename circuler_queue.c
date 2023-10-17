// circular queue
#include <stdio.h>
#define n 5
int f = -1, r = -1, a[n];
void display()
{
    printf("\n");
    int i = f;
    if (f < 0)
    {
        printf("queue is empty...");
    }
    else
    {
        do
        {
            printf("%d ", a[i]);
            i = (i + 1) % n;
        } while (i != (r + 1) % n);
    }
}
void insert(int val)
{
    if ((r + 1) % n == f)
    {
        printf("queue is fall..");
    }
    else if (r < 0)
    {
        f = r = 0;
        a[r] = val;
        // printf("\ninserted element : %d", val);
    }
    else
    {
        r = (r + 1) % n;
        a[r] = val;
        // printf("\ninserted element : %d", val);
    }
}
void delet()
{
    if (f < 0)
    {
        printf("queue is already empty..");
    }
    else if (f == r)
    {
        // printf("\ndelet element : %d", a[f]);
        f = -1, r = -1;
    }
    else
    {
        // printf("\ndelet element : %d", a[f]);
        f = (f + 1) % n;
    }
}
int main()
{
    int ch, x;

    printf("1.insert circular");
    printf("\n2.delet circular");
    printf("\n3.display");
    printf("\n0.exit");

    while (ch != 0)
    {
        printf("\nenter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nadd element : ");
            scanf("%d", &x);
            insert(x);
            break;

        case 2:
            delet();
            break;

        case 3:
            display();
            break;
        case 0:
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}
// int main()
// {
//     insert(10);
//     insert(20);
//     insert(30);
//     insert(40);
//     insert(50);
//     display();

//     delet();
//     delet();
//     delet();
//     // display();

//     insert(111);
//     display();
// }