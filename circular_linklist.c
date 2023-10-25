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
        while (ptr->next != head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }
    printf("\n");
}
void insertend(int val)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        return;
    }
    while (ptr->next != head)

        ptr = ptr->next;

    ptr->next = temp;
    temp->next = head;
    return;
}
void deletend()
{
    struct node *ptr = head;
    struct node *prev;

    if (head == NULL)
    {
        printf("\nlist is already empty");
    }
    else if (ptr->next == head)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != head)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = head;
        free(ptr);
    }
    return;
}

void insertfirst(int val)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        return;
    }
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
    head = temp;
    return;
}
void deletfirst()
{
    struct node *ptr = head;
    struct node *temp = head;

    if (head == NULL)
    {
        printf("list is already empty\n");
    }
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp->next;
    head = temp->next;
    free(temp);
    return;
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
//     int x, y, ch;
//     printf("1.insert end circular");
//     printf("\n2.delet end circular");
//     printf("\n3.insert first circular");
//     printf("\n4.delet first circular");
//     printf("\n5.insert mid circular");
//     printf("\n6.delet mid circular");
//     printf("\n9.display");
//     printf("\n0.Exit");

//     while (ch != 0)
//     {
//         printf("\nenter the choice : ");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             printf("\nenter the element : ");
//             scanf("%d", &x);
//             insertend(x);
//             break;
//         case 2:
//             deletend();
//             break;

//         case 3:
//             printf("\nenter the element : ");
//             scanf("%d", &x);
//             insertfirst(x);
//             break;
//         case 4:
//             deletfirst();
//             break;

//         case 5:
//             printf("\nenter the element : ");
//             scanf("%d", &x);
//             printf("\nenter the position : ");
//             scanf("%d", &y);
//             insertmid(x, y);
//             break;
//         case 6:
//             printf("\nmid delet : ");
//             scanf("%d", &x);
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
//}

int main()
{
    insertend(10);
    insertend(20);
    insertfirst(30);
    insertfirst(40);
    display();
}    