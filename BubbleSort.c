#include <stdio.h>

int insert(int *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter Number %d:", i + 1);
        scanf("%d", A + i);
    }
    return 0;
}
int bubble(int *A, int len)
{
    int exchange = 0;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (*(A + j) > *(A + j + 1))
            {
                exchange = 1;
                int temp;
                temp = *(A + j);
                *(A + j) = *(A + j + 1);
                *(A + j + 1) = temp;
            }
        }
        if (exchange == 0)
        {
            break;
        }
    }
    return 0;
}

int main()
{
    int num;
    printf("Enter number you want:");
    scanf("%d", &num);

    int data[num];
    insert(data, num);
    bubble(data, num);

    printf("\nSoeted data:");
    for (int i = 0; i < num; i++)
    {
        printf("%d,", data[i]);
    }
    return 0;
}