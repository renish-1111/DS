#include <stdio.h>
#include <stdlib.h>

int F = -1;
int R = -1;

void Insert();
void Delete();
void Display();

int main()
{
    int size;
    int i;
    int *Q;
    int choice;

    printf("Enter size of Queue:");
    scanf("%d", &size);
    int Queue[size];
    Q = Queue;

    while (1)
    {
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.End");
        printf("\n\nEnter Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert:");
            scanf("%d", &i);
            Insert(Q, size, i);
            break;
        case 2:
            Delete(Q, size);
            break;
        case 3:
            Display(Q, size);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}

void Insert(int *Q, int size, int i)
{
    
    if ((R + 1) % size == F)
        printf("Over Flow!!");
    else if (F == -1 && R == -1)
    {
        F = R = 0;
        *(Q + R) = i;
    }
    else
    {
        R = (R + 1) % size;
        *(Q + R) = i;
    }
}
void Delete(int *Q, int size)
{
    if (F == -1 && R == -1)
        printf("Under Flow!!");

    else if (R == F)
    {
        printf("Deleted element is %d", *(Q + F));
        R = F = -1;
    }
    else
    {
        printf("Deleted element is %d", *(Q + F));
        F = (F + 1) % size;
    }
}
void Display(int *Q, int size)
{
    if (F == -1 && R == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        int i = F;
        while (i != R)
        {
            printf("%d  ", *(Q + i));
            i = (i + 1) % size;
        }
        printf("%d", *(Q + i));
    }
}