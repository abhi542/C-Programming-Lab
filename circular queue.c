//Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 4 // 4 elements can be in the QUEUE

void insert(int *f, int *r, int q[MAX]);
void delete (int *f, int *r, int q[MAX]);
void display(int *f, int *r, int q[MAX]);

int main()
{
    int f = -1, r = -1, ch;
    int q[MAX];

    do
    {
        printf("1. Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(&f, &r, q);
            break;
        case 2:
            delete (&f, &r, q);
            break;
        case 3:
            display(&f, &r, q);
            break;
        default:
            exit(0);
        }
    } while (ch != 4);
}

void insert(int *f, int *r, int q[MAX])
{
    int item;
    if (*f == (*r + 1) % MAX)
    {
        printf("Queue id Full\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &item);
    *r = (*r + 1) % MAX;
    q[*r] = item;
    if (*f == -1)
        *f = *f + 1;
}

void delete (int *f, int *r, int q[MAX])
{
    if (*f == -1)
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deleted item is %d \n", q[*f]);
    *f = (*f + 1) % MAX;
}

void display(int *f, int *r, int q[MAX])
{
    int i;
    if (*f == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements \n");

    for (i = *f; i <= *r; i++)
    {
        printf("%d\n", q[i]);
    }

    if (*f > *r)
    {
        for (i = *f; i < MAX; i++)
            printf("%d\n", q[i]);
        for (i = 0; i < *f; i++)
            printf("%d\n", q[i]);
    }
}