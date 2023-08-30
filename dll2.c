//Double Linked List - Basics
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int num;
    struct node *prev, *next;
} * NODE;

NODE getnode() { return (NODE)malloc(sizeof(struct node)); } //allocate node memory

int isempty(NODE first) //checks if list is empty
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return 1;
    }
    return 0; //return 0 if list is not empty
}

int getnum() //input and return the data for newnode
{
    int n;
    printf("Enter a no: ");
    scanf("%d", &n);
    return n;
}

NODE insertbeg(NODE first)
{
    NODE newnode = getnode();
    newnode->num = getnum();
    newnode->next = NULL;
    newnode->prev = NULL;
    if (first == NULL)
        return newnode;
    newnode->next = first;
    first->prev = newnode;
    return newnode;
}

NODE insertend(NODE first)
{
    NODE newnode = getnode(), t;
    newnode->num = getnum();
    newnode->next = NULL;
    newnode->prev = NULL;
    if (first == NULL)
        return newnode;
    for (t = first; t->next != NULL; t = t->next)
        ; //traverse to last element
    t->next = newnode;
    newnode->prev = t;
    return first;
}

NODE delbeg(NODE first)
{
    NODE t = first;
    printf("Deleted element: %d\n", first->num);
    if (first->next == NULL)
        return NULL;
    first = first->next;
    first->prev = NULL;
    free(t);
    return first;
}

NODE delend(NODE first)
{
    NODE t;
    if (first->next == NULL)
    {
        printf("Deleted element: %d\n", first->num);
        return NULL;
    }
    for (t = first; t->next != NULL; t = t->next)
        ; //traverse to last element

    printf("Deleted element: %d\n", t->num);
    t->prev->next = NULL;
    free(t);
    return first;
}

void display(NODE first)
{
    int c = 0;
    NODE t;
    printf("\nForward traversal:\n");
    printf("NULL");
    for (t = first; t != NULL; t = t->next, c++)
        printf(" <=> %d <=> ", t->num);
    printf("NULL\n");
    printf("No of nodes: %d\n", c);
}

void backward(NODE first)
{
    NODE t;
    for (t = first; t->next != NULL; t = t->next)
        ; //traverse to last element

    printf("\nReverse traversal:\n");
    printf("NULL");
    for (; t != NULL; t = t->prev)
        printf(" <=> %d <=> ", t->num);
    printf("NULL\n");
}

int main()
{
    NODE first = NULL;
    int ch;
    do
    {
        printf("\n1-Insert beg\n2-Insert end\n3-Delete beg\n4-Delete end\n5-Display\n6-Reverse display\n7-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insertbeg(first);
            break;
        case 2:
            first = insertend(first);
            break;
        case 3:
            if (!isempty(first))
                first = delbeg(first);
            break; //if first is not empty then call the function
        case 4:
            if (!isempty(first))
                first = delend(first);
            break;
        case 5:
            if (!isempty(first))
                display(first);
            break;
        case 6:
            if (!isempty(first))
                backward(first);
            break;
        default:
            break;
        }
    } while (ch != 7);
    return 0;
}