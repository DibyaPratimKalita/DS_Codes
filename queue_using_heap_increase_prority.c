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

void increasePriority(PriorityQueue* pq, char* data, int newPriority) {
    int i;
    for (i = 0; i < pq->size; ++i) {
        if (pq->heap[i].data == data) {
            if (newPriority < pq->heap[i].priority) {
                printf("New priority should be greater than the current priority.\n");
                return;
            }
            pq->heap[i].priority = newPriority;
            while (i != 0 && pq->heap[(i - 1) / 2].priority > pq->heap[i].priority) {
                swap(&pq->heap[(i - 1) / 2], &pq->heap[i]);
                i = (i - 1) / 2;
            }
            return;
        }
    }
    printf("Node not found in the priority queue.\n");
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

    // Increase the priority of a node (e.g., "Task 3") to 10
    increasePriority(pq, "Task 3", 10);
    printf("\nAfter increasing priority of Task 3 to 10:\n");
    printPriorityQueue(pq);

    free(pq->heap);
    free(pq);
    return 0;
}
