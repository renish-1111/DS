#include <stdio.h>
#include <stdlib.h>

int F = -1;
int R = -1;

void insert();
void delete();
void display();

int main()
{
    int size;
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
            insert(Q, size);
            break;
        case 2:
            delete (Q);
            break;
        case 3:
            display(Q);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}

void insert(int *Q, int size)
{
    int i;
    if (R >= size - 1)
        printf("Over Flow!!");
    else
    {
        printf("Enter element to insert:");
        scanf("%d", &i);
        ++R;
        *(Q + R) = i;
    }
    if (F == -1)
        F = 0;
}
void delete(int *Q)
{
    if (R == -1)
        printf("Under Flow!!");
    else if (R == F)
        R = F = -1;
    else
    {
        printf("Deleted element is %d", *(Q + F));
        F++;
    }
}
void display(int *Q)
{
    if (R == -1)
        printf("Queue is empty");
    else
        for (int i = F; i <= R; i++)
            printf("%d  ", *(Q + i));
}