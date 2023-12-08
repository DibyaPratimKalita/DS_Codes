#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char* data;
} Node;

typedef struct {
    Node* heap;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (Node*)malloc(capacity * sizeof(Node));
    return pq;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->heap[left].priority < pq->heap[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->heap[idx], &pq->heap[smallest]);
        minHeapify(pq, smallest);
    }
}

void insert(PriorityQueue* pq, int priority, char* data) {
    if (pq->size == pq->capacity) {
        printf("Priority queue is full!\n");
        return;
    }

    Node newNode;
    newNode.priority = priority;
    newNode.data = data;

    int i = pq->size;
    pq->heap[i] = newNode;
    pq->size++;

    while (i != 0 && pq->heap[(i - 1) / 2].priority > pq->heap[i].priority) {
        swap(&pq->heap[(i - 1) / 2], &pq->heap[i]);
        i = (i - 1) / 2;
    }
}

Node extractMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty!\n");
        Node emptyNode;
        emptyNode.data = NULL;
        emptyNode.priority = -1;
        return emptyNode;
    }

    Node minNode = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return minNode;
}

void printPriorityQueue(PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; ++i) {
        printf("(%d, %s) ", pq->heap[i].priority, pq->heap[i].data);
    }
    printf("\n");
}

int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    insert(pq, 5, "Task 1");
    insert(pq, 2, "Task 2");
    insert(pq, 8, "Task 3");
    insert(pq, 1, "Task 4");

    printPriorityQueue(pq);

    while (pq->size > 0) {
        Node minNode = extractMin(pq);
        printf("Next item: (%d, %s)\n", minNode.priority, minNode.data);
    }

    free(pq->heap);
    free(pq);
    return 0;
}
