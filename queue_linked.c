#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next; 
};

struct queue {
    struct node *front; 
    struct node *rear; 
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
}

struct queue *create_queue() {
    struct queue *new_queue = (struct queue *)malloc(sizeof(struct queue)); 
    new_queue->front = NULL; 
    new_queue->rear = NULL; 
    return new_queue; 
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = create_node(data); 
    if (q->rear == NULL) { 
        q->front = new_node; 
        q->rear = new_node; 
    } else { 
        q->rear->next = new_node; 
        q->rear = new_node; 
    }
}

int dequeue(struct queue *q) {
    if (q->front == NULL) { 
        printf("Queue is empty\n"); 
        return -1; 
    } else { 
        struct node *temp = q->front; 
        int data = temp->data; 
        q->front = q->front->next; 
        free(temp); 
        if (q->front == NULL) { 
            q->rear = NULL; 
        }
        return data; 
    }
}

void print_queue(struct queue *q) {
    struct node *temp = q->front; 
    printf("Queue: "); 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    }
    printf("\n"); 
}

int main() {
    struct queue *q = create_queue(); 
    enqueue(q, 10); 
    enqueue(q, 20); 
    enqueue(q, 30); 
    print_queue(q); 
    printf("Dequeued element: %d\n", dequeue(q)); 
    printf("Dequeued element: %d\n", dequeue(q)); 
    print_queue(q); 
    enqueue(q, 40); 
    enqueue(q, 50); 
    print_queue(q); 
    printf("Dequeued element: %d\n", dequeue(q)); 
    print_queue(q); 
    return 0; 
}