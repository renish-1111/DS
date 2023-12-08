// Write a program to implement following operation on the Doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Create Doubly Linkked List
struct node *create(struct node *head)
{
    struct node *new;
    struct node *ptr;
    int val;
    printf("\nEnter -1 to End\n");
    printf("\nEnter value : ");
    scanf("%d",&val);

    while (val != -1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = val;
        if(head == NULL)        
        {
            new->prev = NULL;
            new->next = NULL;
            head = new;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new;
            new->prev = ptr;
            new->next = NULL;
        }
        printf("Enter value : ");
        scanf("%d",&val);
    }
    return head;
}

// Display Doubly Linked List
void display(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Empty Linked List\n");
    }
    else
    {
        printf("Doubly Linked List : ");
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n\n");
    }
}

//(a) Insert a node at front of the Linked List

struct node *Insert_at_front(struct node *head, int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
    return head;
}

//(b) Insert a node at the End of the linked list

struct node *Insert_at_end(struct node *head, int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->prev = ptr;
    }
    return head;
}

//(c) Delete a last node of the linked list

struct node *Delete_last(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Empty Linked List\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("%d is deleted\n",ptr->data);
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}

//(d) Delete a node before specified position

struct node *Del_before_pos(struct node *head, int num)
{
    struct node *ptr = head;
    struct node *temp;
    if (head == NULL)
    {
        printf("Empty Linked List\n");
    }
    else
    {
        while (ptr->data != num)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Incorrect position...!\n");
            }
        }
        temp = ptr->prev;
        temp->prev->next = ptr;
        ptr->prev = temp->prev;
        printf("%d is Deleted\n",temp->data);
        free(temp);
    }
    return head;
}

int main()
{
    int val;
    int num;
    int choice;
    struct node *head = NULL;
    
    printf("\n**Main Menu**\n");
    printf("1.Create Doubly Linkedlist\n");
    printf("2.Insert a node at the Front\n");
    printf("3.Insert a node at the End\n");
    printf("4.Delete a last node\n");
    printf("5.Delete a node before position\n");
    printf("6.Dispaly Doubly Linked List\n");
    printf("7.Exiting program\n");
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {

        case 1:
            printf("\nCreate Doubly Linked List");
            head = create(head);
            break;

        case 2:
            printf("Enter value : ");
            scanf("%d",&val);
            head = Insert_at_front(head,val);
            break;

        case 3:
            printf("Enter value : ");
            scanf("%d",&val);
            head = Insert_at_end(head,val);
            break;

        case 4:
            head = Delete_last(head);
            break;

        case 5:
            printf("Enter position : ");
            scanf("%d",&num);
            head = Del_before_pos(head,num);
            break;

        case 6:
            display(head);
            break;

        default:
            printf("Exiting program...!\n");
            exit(0);
            break;
        }
    }
    return 0;
}