//Double Ended Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int a[MAX], r = -1, f = 0, te = 0, ch, n, i, x; //te --> total elements

int main()
{
    do
    {
        printf("\n1.Insert Rear\n2.Delete Rear\n3.Insert Front\n4.Delete Front\n5.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addr();
            break;
        case 2:
            delr();
            break;
        case 3:
            addf();
            break;
        case 4:
            delf();
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
    } while (ch != 6);
}

void addr()
{
    if (te == MAX)
        printf("Queue is full\n");
    else
    {
        printf("Enter the number: ");
        scanf("%d", &n);
        r = (r + 1) % MAX;
        a[r] = n;
        te++;
    }
}

void delr()
{
    if (te == 0)
        printf("QUeue is empty\n");
    else
    {
        if (r == -1)
            r = MAX - 1;
        printf("Deleted element is %d\n", a[r]);
        r--;
        te--;
    }
}

void addf()
{
    if (te == MAX)
        printf("Queue is full\n");
    else
    {
        printf("Enter the number: ");
        scanf("%d", &n);

        if (f == 0)
            f = MAX - 1;
        else
            f--;

        a[f] = n;
        te++;
    }
}

void delf()
{
    if (te == 0)
        printf("Queue id empty\n");
    else
    {
        printf("Deleted element is %d\n", a[f]);
        f = (f + 1) % MAX;
        te--;
    }
}

void display()
{
    if (te == 0)
        printf("Queue is empty\n");
    else
    {
        x = f;
        for (i = 1; i <= te; i++, x = (x + 1) % MAX)
            printf("%d-", a[x]);
    }
}
