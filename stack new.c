#include <stdio.h>
#include <stdlib.h>

int top = 0;
void push();
void pop();
void show();

int main()
{
    int SIZE;
    printf("Enter Size:");
    scanf("%d", &SIZE);
    int inp_array[SIZE];

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
            push(SIZE, inp_array);
            break;
        case 2:
            pop(inp_array);
            break;
        case 3:
            show(inp_array);
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push(int SIZE, int *inp_array)
{

    if (top < SIZE)
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", inp_array + top);
        top = top + 1;
    }
    else
    {
        printf("\nOverflow!!");
    }
}

void pop(int *inp_array)
{
    if (top > 0)
    {
        printf("\nPopped element: %d", *(inp_array + top));
        top = top - 1;
    }
    else
    {
        printf("\nUnderflow!!");
    }
}

void show(int *inp_array)
{
    if (top > 0)
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
        {
            printf("%d\n", *(inp_array + i - 1));
        }
    }
    else
    {
        printf("\nUnderflow!!");
    }
}