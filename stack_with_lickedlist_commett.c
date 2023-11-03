#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
    int size;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct stack* create_stack() {
    struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

void push(struct stack* s, int data) {
    struct node* new_node = create_node(data);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int data = s->top->data;
    struct node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

int peek(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int is_empty(struct stack* s) {
    return s->top == NULL;
}

void display(struct stack* s) {
    struct node* curr = s->top;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct stack* s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);
    printf("Popped element: %d\n", pop(s));
    printf("Top element: %d\n", peek(s));
    printf("Stack size: %d\n", s->size);
    printf("Stack empty: %d\n", is_empty(s));
    return 0;
}