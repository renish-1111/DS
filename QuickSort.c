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
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int pivot(int *arr, int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    do
    {
        while (*(arr+i) <= pivot)
        {
            i++;
        }

        while (*(arr+j) > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr+i,arr+j);
        }
    } while (i < j);

    // Swap A[low] and A[j]
    swap(arr+low,arr+j);
    return j;
}

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int P = pivot(arr, low, high);

        QuickSort(arr, 0, P - 1);
        QuickSort(arr, P + 1, high);
    }
}
int main()
{

    int num;
    printf("Enter number you want:");
    scanf("%d", &num);

    int data[num];
    insert(data, num);

    QuickSort(data, 0, num - 1);

    for (int i = 0; i < num; i++)
    {
        printf("%d  ", data[i]);
    }

    return 0;
}