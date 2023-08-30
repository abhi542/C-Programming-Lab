#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 50

int top = 0;
s[MAX];

int main()
{
    char a[MAX];
    double res, op1, op2;
    int ele;
    int i;

    void push(int ele);
    int pop();
    printf("Enter suffix expression: ");
    scanf("%s", a);
    i = 0;

    while (a[i] != '\0')
    {
        if (isdigit(a[i]))
            push(a[i] - '\0');
        else
        {
            op2 = pop();
            op1 = pop();

            switch (a[i])
            {
            case '+':
                res = op1 + op2;
                push(res);
                break;

            case '-':
                res = op1 - op2;
                push(res);
                break;

            case '*':
                res = op1 * op2;
                push(res);
                break;

            case '/':
                res = op1 / op2;
                push(res);
                break;

            case '^':
                res = pow(op1, op2);
                push(res);
                break;

            case '%':
                res = op1 / op2;
                push(res);
                break;

            default:
                printf("Invalid expression. \n");
                break;
            }
        }
        i = i + 1;
    }
    printf("Value of the expression = %f", res);
}

void push(int res)
{
    if (top > MAX)
    {
        printf("Overflow");
        return;
    }

    else
    {
        int ele;
        s[top] = ele;
        top++;
    }
}

int pop()
{
    if (top = 0)
        printf("Invalid\n");

    else
        return (s[--top]);

    return 0;
}