#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push();
void pop();
void show();

int main()
{
    int size;
    printf("Enter size of Stack:");
    scanf("%d", &size);

    int stack[size];
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, size - 1);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            show(stack);
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push(int *A,int size)
{
    int x;

    if (top >= size)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        *(A + top) = x;
    }
}

void pop(int *A)
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", *(A+top));
        top = top - 1;
    }
}

void show(int *A)
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", *(A+i));
    }
}