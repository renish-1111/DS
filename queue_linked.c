#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct queue *create_queue()
{
    struct queue *new_queue = (struct queue *)malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

void enqueue(struct queue *q, int data)
{
    struct node *new_node = create_node(data);
    if (q->rear == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        struct node *temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        free(temp);
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        return data;
    }
}

void print_queue(struct queue *q)
{
    struct node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct queue *q = create_queue();
    int i;
    int choice;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.End\n");
    while (1)
    {
        printf("\nEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert:");
            scanf("%d", &i);
            enqueue(q, i);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(q));
            break;
        case 3:
            print_queue(q);
            break;
        case 4:
            exit(0);
            break;
        }
    }

    return 0;
}
