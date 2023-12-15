#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

struct AdjListNode {
    int dest; 
    struct AdjListNode* next; 
};

struct AdjList {
    struct AdjListNode* head; 
};

struct Graph {
    int V; 
    struct AdjList* array; 
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {

    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    int MIN;
    if (isEmpty(queue)) {
        return MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void BFS(struct Graph* graph, int s) {

    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    struct Queue* queue = createQueue(graph->V);

    visited[s] = 1;
    enqueue(queue, s);

    while (!isEmpty(queue)) {

        int u = dequeue(queue);
        printf("%d ", u);

        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            int v = pCrawl->dest;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(queue, v);
            }
            pCrawl = pCrawl->next;
        }
    }
}

void DFS(struct Graph* graph, int v, int* visited) {

    visited[v] = 1;
    printf("%d ", v);

    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        int u = pCrawl->dest;
        if (!visited[u]) {
            DFS(graph, u, visited);
        }
        pCrawl = pCrawl->next;
    }
}

int main() {

    int V = 5; 
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("\nBFS traversal of the graph is: \n");
    BFS(graph, 0);

    printf("\nDFS traversal of the graph is: \n");
    int* visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    DFS(graph, 0, visited);

    return 0;
}