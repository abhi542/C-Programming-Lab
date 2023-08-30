// Double Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char ssn[20], name[20], dept[20], des[20], ph[20];
    int sal;
    struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE insfront(NODE head);
NODE insrear(NODE head);
NODE delfront(NODE head);
NODE delrear(NODE head);
void display(NODE head);
void backtrav(NODE);
NODE getNode();
int count;
int main()
{
    int ch, i, n;
    NODE head;
    head = NULL;
    printf(" Enter the number of the record\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        head = insrear(head);
    for (;;)
    {
        printf("\n\nMenu\n");
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Display reverse\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insfront(head);
            break;
        case 2:
            head = insrear(head);
            break;
        case 3:
            if (head == NULL)
                printf("List Empty");
            else
                head = delfront(head);
            break;
        case 4:
            if (head == NULL)
                printf("List Empty");
            else
                head = delrear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            backtrav(head);
            break;
        case 7:
            exit(0);
        }
    }
}

NODE getNode()
{
    return ((NODE)malloc(sizeof(struct node)));
}

NODE insfront(NODE head)
{
    NODE newnode = getNode();
    printf("Enter Details such as SSN Name Department Designation Salary PhNo\n");
    scanf("%s%s%s", newnode->ssn, newnode->name, newnode->dept);
    scanf("%s%d%s", newnode->des, &newnode->sal, newnode->ph);
    newnode->rlink = NULL;
    newnode->llink = NULL;
    count++;
    //connection
    if (head == NULL)
        return newnode;
    newnode->rlink = head;
    head->llink = newnode;
    return (newnode);
}

NODE insrear(NODE head)
{
    NODE newnode = getNode();
    NODE t = head;
    printf("Enter Details such as SSN Name Department Designation Salary PhNo\n");
    scanf("%s%s%s", newnode->ssn, newnode->name, newnode->dept);
    scanf("%s%d%s", newnode->des, &(newnode->sal), newnode->ph);
    newnode->rlink = NULL;
    newnode->llink = NULL;
    count++;
    if (head == NULL)
        return newnode;
    while (t->rlink != NULL)
        t = t->rlink;
    t->rlink = newnode;
    newnode->llink = t;
    return (head);
}
NODE delfront(NODE head)
{
    NODE t = head;
    printf("Deleted Record is\n");
    printf("%s\t%s\t%s\t%s\t%d\t%s\n", (t->ssn), (t->name), (t->dept), (t->des), (t->sal), (t->ph));
    head = t->rlink;
    free(t);
    count--;
    return (head);
}

NODE delrear(NODE head)
{
    NODE pre, cur = head;
    if (cur->rlink == NULL)
        head = NULL;
    else
    {
        while (cur->rlink != NULL)
            cur = cur->rlink;
        cur->llink->rlink = NULL;
    }
    printf("Deleted Record is\n");
    printf("%s\t%s\t%s\t%s\t%d\t%s\n", (cur->ssn), (cur->name), (cur->dept), (cur->des), (cur->sal), (cur->ph));
    count--;
    free(cur);
    return (head);
}

void display(NODE head)
{
    NODE t = head;
    printf("Total Number of records are %d\n", count);
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    printf("SSN\tName\tDepartment\tDesignation\tSalary\t\tPhNo\n");
    while (t != NULL)
    {
        printf("%s\t%s\t%s\t\t%s\t\t%d\t%s\n", (t->ssn), (t->name), (t->dept), (t->des), (t->sal), (t->ph));
        t = t->rlink;
    }
}
void backtrav(NODE head)
{
    NODE t;
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    for (t = head; t->rlink != NULL; t = t->rlink)
        ;
    while (t != NULL)
    {
        printf("%s\t%s\t%s\t\t%s\t\t%d\t%s\n", (t->ssn), (t->name), (t->dept), (t->des), (t->sal), (t->ph));
        t = t->llink;
    }
}