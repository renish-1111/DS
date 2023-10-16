#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;
int check(char *e)
{
    while (*e != NULL)
    {
        if (1 != isalnum(*e))
        {
            return 0;
        }
        e = +2;
    }
    e = 1;
    while (*e != NULL)
    {
        if (1 == isalnum(*e))
        {
            return 0;
        }
        e = +2;
    }

    return 1;
}
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{

    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    if (check(exp) == 0)
    {
        printf("Invalid exp!!!");
    }
    
    while (*e != '\0')
    {

        if (isalnum(*e))
            printf("%c", *e);
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}