#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push();
void pop();
void peep();
void change();
void display();

int main()
{
    int size;
    printf("Enter size of Stack:");
    scanf("%d", &size);

    int stack[size];
    int choice;
    int i;
    int x;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Peep the element\n4.Change the element\n5.Display\n6.end");
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
            printf("Enter position:");
            scanf("%d", &i);
            peep(stack, i);
            break;
        case 4:
            printf("Enter position:");
            scanf("%d", &i);
            printf("Enter changed number:");
            scanf("%d", &x);
            change(stack, i, x);
            break;
        case 5:
            display(stack);
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push(int *A, int size)
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
        printf("\nUnderflow!!");
    else
    {
        printf("\nPopped element: %d", *(A + top));
        top = top - 1;
    }
}

void peep(int *A, int i)
{
    if (top + 1 - i <= -1)
        printf("\nUnderflow!!");
    else
        printf("\nPeeped element: %d", *(A + top + 1 - i));
}

void change(int *A, int i, int x)
{
    if (top + 1 - i <= -1)
        printf("\nUnderflow!!");
    else
    {
        *(A + top + 1 - i) = x;
        printf("%dth position is change with %d", i , *(A + top + 1 - i));
    }
}

void display(int *A)
{
    if (top == -1)
        printf("\nUnderflow!!");
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", *(A + i));
    }
}