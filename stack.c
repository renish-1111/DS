#include <stdio.h>
void display(int *A, int top)
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", *(A + i));
    }
}
void push(int *A, int top)
{
    if (top != top - 1)
    {
        printf("Enter number for puss:");
        scanf("%d", (A + top));
        top = top - 1;
    }
    else
    {
        printf("Over Flow");
    }
}
void pop(int *A, int top)
{
    scanf("%d", *(A + top));
    top = top - 1;
}
int main()
{
    int size;
    printf("Enter size of Stack:");
    scanf("%d", &size);

    int stack[size];
    int n;

MENU:
    printf("1.PUSS \n2.POP \n");
    printf("Enter number:");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        push(stack, size - 1);
        goto MENU;
        break;

    case 2:
        pop(stack, size - 1);
        goto MENU;
        break;

    case 3:
        display(stack, size - 1);
        break;
    }
    return 0;
}