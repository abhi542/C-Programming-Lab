#include <stdio.h>
#include <stdlib.h>
#define MAX 3

void push(int stack[10], int *top);
void pop(int stack[10], int *top);
void display(int stack[10], int *top);
int main()
{
    int top = -1, stack[MAX], ch;

    do
    {
        printf("1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(stack, &top);
            break;

        case 2:
            pop(stack, &top);
            break;

        case 3:
            display(stack, &top);
            break;

        default:
            break;
        }
    } while (ch != 4);
    return 0;
}

void push(int stack[10], int *top)
{
    int item;
    if (*top = MAX - 1)
        printf("Stack is Overflow");
    else
    {
        printf("Enter the item: ");
        scanf("%d", &item);
        *top = *top + 1;
        stack[*top] = item;
    }
}

void pop(int stack[10], int *top)
{
    if (top == -1)
        printf("Stack is Underflow");
    else
    {
        printf("Deleted Item is %d", stack[*top]);
        *top = *top - 1;
    }
}

void display(int stack[10], int *top)
{

    if (top == -1)
        printf("Stack is empty");
    else
    {
        printf("Stack elements are: ");

        for (int i = *top; i >= 0; i--)
            printf("%d \n", stack[i]);
    }
}