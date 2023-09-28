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

} s[5], temp;

void sorting_by_name()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nname:%s\n", s[i].name);
        printf("enroll:%d\n", s[i].enroll);
        printf("math mark:%d\n", s[i].sub.math);
        printf("phy mark:%d\n", s[i].sub.phy);
        printf("chem mark:%d\n", s[i].sub.chem);
    }
}
void sorting_by_enroll()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if (s[i].enroll > s[j].enroll)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nname:%s\n", s[i].name);
        printf("enroll:%d\n", s[i].enroll);
        printf("math mark:%d\n", s[i].sub.math);
        printf("phy mark:%d\n", s[i].sub.phy);
        printf("chem mark:%d\n", s[i].sub.chem);
    }
}
void sorting_by_mark()
{
    for (int i = 0; i < 5; i++)
    {
        s[i].sub.avg = (s[i].sub.math + s[i].sub.phy + s[i].sub.chem) / 3;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if (s[i].sub.avg < s[j].sub.avg)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nname:%s\n", s[i].name);
        printf("enroll:%d\n", s[i].enroll);
        printf("math mark:%d\n", s[i].sub.math);
        printf("phy mark:%d\n", s[i].sub.phy);
        printf("chem mark:%d\n", s[i].sub.chem);
    }
}
int main()
{

    int num;

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

lable:

    printf("\nPRESS 1 SORTING BY NAME\n");
    printf("PRESS 2 SORTING BY ENROLL\n");
    printf("PRESS 3 SORTING BY AVG MARK\n");
    printf("PRESS 4 RETURN\n");

    printf("Enter Number:");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        sorting_by_name();
        goto lable;
        break;
    case 2:
        sorting_by_enroll();
        goto lable;
        break;
    case 3:
        sorting_by_mark();
        goto lable;
        break;
    case 4:
        break;
    }
    return 0;
}
