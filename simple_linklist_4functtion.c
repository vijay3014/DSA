// malloc => alloction => heap
// simple link list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

int display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
void insertend(int val)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (ptr->next != NULL)

    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return;
}
void deletend()
{
    struct node *ptr = head;
    struct node *prev;

    if (head == NULL)
    {
        printf("list is already empty\n");
    }
    else if (ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
    return;
}

void insertfirst(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    temp->next = head;
    head = temp;
}
void deletfirst()
{
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
}

void insertmid(int val, int posi)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    struct node *prev;

    while (ptr->data != posi)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = temp;
    temp->next = ptr;
    return;
}
void deletmid(int posi)
{
    struct node *ptr = head;
    struct node *prev;

    while (ptr->data != posi)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return;
}
// int main()
// {
//     int ch, x, y;

//     printf("1.insert end malloc");
//     printf("\n2.delet end malloc");
//     printf("\n3.insert first malloc");
//     printf("\n4.delet first malloc");
//     printf("\n5.insert mid malloc");
//     printf("\n6.delet mid malloc");
//     printf("\n9.display");
//     printf("\n0.exit");

//     while (ch != 0)
//     {
//         printf("\nenter choice : ");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             printf("\nadd element : ");
//             scanf("%d", &x);
//             insertend(x);
//             break;

//         case 2:
//             deletend();
//             break;

//         case 3:
//             printf("\nadd element : ");
//             scanf("%d", &x);
//             insertfirst(x);
//             break;

//         case 4:
//             deletfirst();
//             break;

//         case 5:
//             printf("\nadd element : ");
//             scanf("%d", &x);
//             printf("\nadd position : ");
//             scanf("%d", &y);
//             insertmid(x,y);
//             break;

//         case 6:
//             deletmid(x);
//             break;

//         case 9:
//             display();
//             break;

//         case 0:
//             break;

//         default:
//             printf("wrong choice");
//             break;
//         }
//     }
// }

int main()
{
    insertend(10);
    insertend(20);
    insertend(30);
    insertend(40);
    insertend(50);
    display();

    deletend();
    // deletend();
    deletmid(30);
    deletfirst(10);
    display();
}