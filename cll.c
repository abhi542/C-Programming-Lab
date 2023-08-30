#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int num;
    struct node *next;
} * NODE;

NODE getnode() { return (NODE)malloc(sizeof(struct node)); } //allocate node memory

int isempty(NODE last) //checks if list is empty
{
    if (last == NULL)
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

NODE insertbeg(NODE last)
{
    NODE newnode = getnode();
    newnode->num = getnum();
    if (last == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return last;
}

NODE insertend(NODE last)
{
    NODE newnode = getnode();
    newnode->num = getnum();
    if (last == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return newnode;
}

NODE delbeg(NODE last)
{
    if (isempty(last))
        return NULL;
    printf("Deleted element: %d\n", last->next->num);
    if (last->next == last)
    {
        free(last);
        return NULL;
    }
    NODE t = last->next;
    last->next = last->next->next;
    free(t);
    return last;
}

NODE delend(NODE last)
{
    printf("Deleted element: %d\n", last->num);
    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        NODE t = last->next;
        while (t->next != last)
            t = t->next;
        t->next = last->next;
        free(last);
        last = t;
    }
    return last;
}

void display(NODE last)
{
    int c = 0;
    NODE t;
    t = last->next;
    do
    {
        printf("%d => ", t->num);
        t = t->next;
        c++;
    } while (t != last->next);
    printf("\nNo of nodes: %d\n", c);
}

int main()
{
    NODE last = NULL;
    int ch;
    do
    {
        printf("\n1-Insert beg\n2-Insert end\n3-Delete beg\n4-Delete end\n5-Display\n6-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            last = insertbeg(last);
            break;
        case 2:
            last = insertend(last);
            break;
        case 3:
            if (!isempty(last))
                last = delbeg(last);
            break;
        case 4:
            if (!isempty(last))
                last = delend(last);
            break;
        case 5:
            if (!isempty(last))
                display(last);
            break;
        default:
            break;
        }
    } while (ch != 6);
    return 0;
}