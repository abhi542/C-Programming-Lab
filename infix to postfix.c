#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define size 50

char stack[size];
int top = -1;

int main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    push('#');

    while ((ch = infix[i]) != '\0')
    {
        if (ch == '(')
            push(ch); //pushes to stack

        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }

        else //operations
        {
            while (pr(stack[top] >= pr(ch)) // checking priority/precedence
                postfix[k++] = pop();
            push(ch);
        }

        i++;
        return 0;
    }

    while (stack[top] != '#')
    {
        postfix[k++] = pop();

        postfix[k] = '\0';
    }
    printf("Postfix Expression is %s \n:", postfix);
    return 0;
}

char push(char elem)
{
    stack[++top] = elem;
    return 0;
}

char pop() return (stack[top--]);

int pr(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/' || symbol == '%')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}