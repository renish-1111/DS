#include <stdio.h>
void insert(int *A, int len)
{

    for (int i = 0; i < len; i++)
    {
        printf("Enter number %d:", i + 1);
        scanf("%d", A + i);
    }
}
void sort(int *A, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j <= len; j++)
        {
            if (*(A + i) > *(A + j))
            {
                int temp;

                temp = *(A + i);
                *(A + i) = *(A + j);
                *(A + j) = temp;
            }
        }
    }
}

void binary(int *A, int len, int key)
{
    int low = 0;
    int high = len - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;

        if (*(A + mid) == key)
        {
            printf("\n%d is found at %d", key, mid + 1);
            return;
        }
        else if (*(A + mid) > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("\nNot Found!!!!");
    return;
}

void main()
{
    int num;

    printf("Enter num want to enter:");
    scanf("%d", &num);

    int data[num];
    insert(data, num);

    sort(data, num);

    printf("\nSorted:");

    for (int i = 0; i < num; i++)
    {
        printf("%d,", data[i]);
    }

    int key;
    printf("\nEnter want find:");
    scanf("%d", &key);

    binary(data, num, key);
}