#include <stdio.h>

void insert(int *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter Number %d:", i + 1);
        scanf("%d", A + i);
    }
}

void merge(int *A, int mid, int low, int high)
{
    int i, j, k, B[high];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (*(A + i) < *(A + j))
        {
            B[k] = *(A + i);
            i++;
            k++;
        }
        else
        {
            B[k] = *(A + j);
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = *(A+i);
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = *(A+j);
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        *(A + i) = B[i];
    }
}
void mergesort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int num;
    printf("Enter number want to enter:");
    scanf("%d", &num);

    int data[num];
    insert(data, num);

    mergesort(data, 0, num - 1);

    printf("\nSort:");
    for (int i = 0; i < num; i++)
    {
        printf("%d  ", data[i]);
    }
    return 0;
}