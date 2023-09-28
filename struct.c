#include <stdio.h>
#include <string.h>

struct student
{
    char name[10];
    int enroll;
    struct sub
    {
        int math;
        int phy;
        int chem;
        float avg;
    } sub;

} s[5];

void main()
{
    int x;

    printf("Enter student detail:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nstudent %d\n", i + 1);
        printf("name:");
        scanf("%s", &s[i].name);
        printf("enroll:");
        scanf("%d", &s[i].enroll);
        printf("math mark:");
        scanf("%d", &s[i].sub.math);
        printf("phy mark:");
        scanf("%d", &s[i].sub.phy);
        printf("chem mark:");
        scanf("%d", &s[i].sub.chem);
    }

    printf("\n\nEnter enroll of student:");
    scanf("%d", &x);

    for (int i = 0; i < 5; i++)
    {
        if (x == s[i].enroll)
        {
            printf("\nname:%s\n", s[i].name);
            printf("enroll:%d\n", s[i].enroll);
            printf("math mark:%d\n", s[i].sub.math);
            printf("phy mark:%d\n", s[i].sub.phy);
            printf("chem mark:%d\n", s[i].sub.chem);
        }
    }
}