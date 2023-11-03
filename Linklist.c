#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *head = NULL;

struct node *create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->link = NULL;
    return newnode;
}

void insert_front(int data)
{
    struct node *newnode = create_node(data);
    newnode->link = head;
    head = newnode;
}

void insert_end(int data)
{
    struct node *newnode = create_node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void insert_order(int data)
{
    struct node *newnode = create_node(data);
    if (head == NULL || head->info >= data)
    {
        newnode->link = head;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL && temp->link->info < data)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
}

void delete_before(int pos)
{
    if (head == NULL || pos <= 1)
    {
        printf("Deletion not possible.\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        int count = 1;
        while (temp->link != NULL && count < pos - 1)
        {
            prev = temp;
            temp = temp->link;
            count++;
        }
        if (count == pos - 1)
        {
            if (prev == NULL)
            {
                head = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }
            free(temp);
        }
        else
        {
            printf("Deletion not possible.\n");
        }
    }
}

void delete_after(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = head;
        int count = 1;
        while (temp->link != NULL && count < pos)
        {
            temp = temp->link;
            count++;
        }
        if (count == pos && temp->link != NULL)
        {
            struct node *del = temp->link;
            temp->link = del->link;
            free(del);
        }
        else
        {
            printf("Deletion not possible.\n");
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int choice, data, pos;
    printf("Menu:\n");
    printf("1. Insert a node at the front of the list.\n");
    printf("2. Insert a node at the end of the list.\n");
    printf("3. Insert a node such that the list is in ascending order.\n");
    printf("4. Delete the first node of the list.\n");
    printf("5. Delete a node before a specified position.\n");
    printf("6. Delete a node after a specified position.\n");
    printf("7. Display the list.\n");
    printf("8. Exit.\n");

    do
    {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insert_front(data);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 3:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insert_order(data);
            break;
        case 4:
            delete_first();
            break;
        case 5:
            printf("Enter the position: ");
            scanf("%d", &pos);
            delete_before(pos);
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            delete_after(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        }
    } while (1);
}