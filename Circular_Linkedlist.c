#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBeforePosition(struct Node **head, int position, int value)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        int currentPosition = 1;

        if (position == 1)
        {
            newNode->next = *head;
            while (temp->next != *head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            *head = newNode;
        }
        else
        {
            while (temp->next != *head && currentPosition < position - 1)
            {
                temp = temp->next;
                currentPosition++;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteFirstNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *lastNode = *head;

    while (lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }

    *head = temp->next;
    lastNode->next = *head;

    free(temp);
}

void deleteAfterPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = *head;
    int currentPosition = 1;

    while (temp->next != *head && currentPosition < position)
    {
        temp = temp->next;
        currentPosition++;
    }

    if (currentPosition == position && temp->next != *head)
    {
        struct Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    else
    {
        printf("Invalid position or position too close to the end\n");
    }
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

void freeList(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *temp = *head;
    struct Node *nextNode;

    do
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}

int main()
{
    struct Node *head = NULL;

    printf("1. Insert a node at the end of the linked list.\n");
    printf("2. Insert a node before specified position.\n");
    printf("3. Delete the first node of the linked list.\n");
    printf("4. Delete a node after specified position.\n");
    printf("5. Display.\n");
    printf("6. End.\n");

    int choice, data, position;

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted at the end of the linked list: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 2:
            printf("Enter position:");
            scanf("%d", &position);
            printf("Enter the data to be inserted before specified position: ");
            scanf("%d", &data);
            insertBeforePosition(&head, position, data);
            break;
        case 3:
            deleteFirstNode(&head);
            break;
        case 4:
            printf("Enter position:");
            scanf("%d", &position);
            deleteAfterPosition(&head, position);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            freeList(&head);
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (1);

    return 0;
}