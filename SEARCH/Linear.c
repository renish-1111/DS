#include <stdio.h>

int linear(int *A, int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (*(A + i) == key)
        {
            printf("%d is found at %d", key, i + 1);
            return 0;
        }
    }

    printf("Not Found!!!");
    return 1;
}

void main()
{
    int num;

    printf("Enter number want to enter:");
    scanf("%d", &num);

    int data[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter number %d:", i + 1);
        scanf("%d", &data[i]);
    }

    int key;

    printf("\nEnter number want to search:");
    scanf("%d", &key);

    linear(data, num, key);
}