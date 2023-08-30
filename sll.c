//Single Linked List
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *llink, *next;
} * NODE;
NODE insfront(NODE, int);
NODE insrear(NODE, int);
NODE delfront(NODE);
NODE delrear(NODE);
void display(NODE);
void backtrav(NODE);
NODE getNode();
NODE reverse(NODE);
int c = 0;

int isempty(NODE t)
{
    if (t == NULL)
    {
        printf("List Empty\n");
        return 1;
    }
    return 0;
}

int getnum()
{
    int n;
    printf("Enter a no: \n");
    scanf("%d", &n);
    return n;
}

int main()
{
    int ch, i, n;
    NODE head = NULL, rev;
    for (;;)
    {
        printf("\n\nMenu\n");
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Display reverse\n7-Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insfront(head, getnum());
            break;
        case 2:
            head = insrear(head, getnum());
            break;
        case 3:
            if (!isempty(head))
                head = delfront(head);
            break;
        case 4:
            if (!isempty(head))
                head = delrear(head);
            break;
        case 5:
            if (!isempty(head))
                display(head);
            break;
        case 6:
            if (!isempty(head))
                rev = reverse(head);
            break;
        case 7:
            exit(0);
        }
    }
}

NODE getNode() { return (NODE)malloc(sizeof(struct node)); }

NODE insfront(NODE head, int n)
{
    NODE newnode = getNode();
    newnode->data = n;
    newnode->next = NULL;
    c++;
    //connection
    if (head == NULL)
        return newnode;
    newnode->next = head;
    return (newnode);
}

NODE insrear(NODE head, int n)
{
    NODE newnode = getNode(), t = head;
    newnode->data = n;
    newnode->next = NULL;
    c++;
    if (head == NULL)
        return newnode;
    while (t->next)
        t = t->next;
    t->next = newnode;
    newnode->llink = t;
    return (head);
}
NODE delfront(NODE head)
{
    NODE t = head;
    printf("Deleted: %d\n", t->data);
    head = t->next;
    free(t);
    c--;
    return (head);
}

NODE delrear(NODE head)
{
    NODE pre, cur = head;
    if (cur->next == NULL)
        head = NULL;
    else
    {
        while (cur->next)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
    }
    printf("Deleted: %d\n", cur->data);
    c--;
    free(cur);
    return (head);
}

void display(NODE head)
{
    NODE t = head;
    printf("Total Number of elements: %d\n", c);
    while (t)
    {
        printf("%d->", t->data);
        t = t->next;
    }
    printf("NULL\n");
}
NODE reverse(NODE head)
{
    NODE rev = NULL, t;
    while (t)
    {
        rev = insfront(rev, t->data);
        t = t->next;
    }
    t = rev;
    while (t)
    {
        printf("%d->", t->data);
        t = t->next;
    }
    printf("NULL\n");
    return rev;
}