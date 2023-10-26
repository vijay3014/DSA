#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }
    else
    {
        while (ptr->next != NULL)

            ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;
    }
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
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;

    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }
    else
    {
        temp->prev = NULL;
        temp->next = ptr;
        ptr->prev = temp;
        head = temp;
    }
}
void deletfirst()
{
    struct node *ptr = head;
    struct node *temp = head;

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
        head = ptr->next;
        ptr->next->prev = NULL;
        free(ptr);
    }
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
    prev->prev = prev;
    temp->next = ptr;
    ptr->prev = temp;
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
    ptr->prev = ptr->prev->prev;
    free(ptr);
    return;
}

int main()
{
    int x, y, ch;
    printf("1.insert end doubly simple linklist");
    printf("\n2.delet end doubly simple linklist");
    printf("\n3.insert first doubly simple linklist");
    printf("\n4.delet first doubly simple linklist");
    printf("\n5.insert mid doubly simple linklist");
    printf("\n6.delet mid doubly simple linklist");
    printf("\n9.display");
    printf("\n0.Exit");

    while (ch != 0)
    {
        printf("\nenter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nenter the element : ");
            scanf("%d", &x);
            insertend(x);
            break;
        case 2:
            deletend();
            break;

        case 3:
            printf("\nenter the element : ");
            scanf("%d", &x);
            insertfirst(x);
            break;
        case 4:
            deletfirst();
            break;

        case 5:
            printf("\nenter the element : ");
            scanf("%d", &x);
            printf("\nenter the position : ");
            scanf("%d", &y);
            insertmid(x, y);
            break;
        case 6:
            printf("\nmid delet : ");
            scanf("%d", &x);
            deletmid(x);
            break;

        case 9:
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