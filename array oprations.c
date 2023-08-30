#include <stdio.h>
#include <stdlib.h>

void create(int a[10], int n);
void display(int a[10], int n);
void insertpos(int a[10], int n);
void delpos(int a[10], int n);

int main()
{
    int a[10], n, i, ch;

    printf("Menu Driven Array Opeations:\n");

    do
    {
        printf("1.Create \n2.Print \n3.Insert at Position \n4.Delete at Position \n5.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create(a, n);
            break;

        case 2:
            display(a, n);
            break;

        case 3:
            insertpos(a, n);
            break;

        case 4:
            delpos(a, n);
            break;

        default:
            break;
        }
    } while (ch != 4);
    return 0;
}

void create(int a[10], int n)
{
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[10], int n)
{
    printf("The array elements are: ");

    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
}

void insertpos(int a[10], int n)
{
    int pos, ele, i;

    printf("Enter position where insertion to be done: ");
    scanf("%d", &pos);

    printf("Enter element to be inserted: ");
    scanf("%d", &ele);

    for (i = n - 1; i >= pos; i--)
    {
        a[i] = a[i - 1];
        a[pos - 1] = ele;

        display(a, n);
    }
}

void delpos(int a[10], int n)
{
    int pos, i;

    printf("Enter position where deleltion to be done: ");
    scanf("&d", &pos);

    for (i = pos - 1; i < n; i++)
        a[i] = a[i + 1];

    display(a, n);
}