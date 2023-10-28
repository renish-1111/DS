#include <stdio.h>

void TOH(int n, char source, char destination, char helper)
{

    if (n == 0)
    {
        return;
    }

    TOH(n - 1, source, helper, destination);
    printf("\nMove disc %d from tower %c to tower %c", n, source, destination);
    TOH(n - 1, helper, destination, source);
}
int main()
{
    int n;

    printf("Enter number od disk:");
    scanf("%d",&n);

    TOH(n, 'A', 'B', 'C');
    return 0;
}