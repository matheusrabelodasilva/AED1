#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;
void initStack(Stack *s, int cap) {
    s->arr = (int *)malloc(sizeof(int) * cap);
    s->top = -1;
    s->capacity = cap;
}
void pushStack(Stack *s, int val) {
    s->arr[++s->top] = val;
}
int peekStack(Stack *s) {
    return s->arr[s->top];
}
void popStack(Stack *s) {
    s->top--;
}
bool isStackEmpty(Stack *s) {
    return s->top == -1;
}
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;
void initQueue(Queue *q, int cap) {
    q->arr = (int *)malloc(sizeof(int) * cap);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = cap;
}
void enqueue(Queue *q, int val) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}
int peekQueue(Queue *q) {
    return q->arr[q->front];
}
void dequeue(Queue *q) {
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}
bool isQueueEmpty(Queue *q) {
    return q->size == 0;
}
typedef struct {
    int *arr;
    int size;
    int capacity;
} PriorityQueue;
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
void initPriorityQueue(PriorityQueue *pq, int cap) {
    pq->arr = (int *)malloc(sizeof(int) * cap);
    pq->size = 0;
    pq->capacity = cap;
}
void enqueuePQ(PriorityQueue *pq, int val) {
    pq->arr[pq->size++] = val;
}
int peekPQ(PriorityQueue *pq) {
    if (pq->size == 0) return -1; 
    qsort(pq->arr, pq->size, sizeof(int), compare); 
    return pq->arr[0];
}
void dequeuePQ(PriorityQueue *pq) {
    if (pq->size == 0) return;
    qsort(pq->arr, pq->size, sizeof(int), compare);
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}
bool isPriorityQueueEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}
int main() {
    int n, op_type, value;
    while (scanf("%d", &n) != EOF) {
        Stack s;
        Queue q;
        PriorityQueue pq;
        initStack(&s, n);
        initQueue(&q, n);
        initPriorityQueue(&pq, n);
        bool is_stack = true;
        bool is_queue = true;
        bool is_priority_queue = true;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &op_type, &value);
            if (op_type == 1) {
                if (is_stack) pushStack(&s, value);
                if (is_queue) enqueue(&q, value);
                if (is_priority_queue) enqueuePQ(&pq, value);
            } else { 
                if (is_stack) {
                    if (isStackEmpty(&s) || peekStack(&s) != value) {
                        is_stack = false;
                    } else {
                        popStack(&s);
                    }
                }
                if (is_queue) {
                    if (isQueueEmpty(&q) || peekQueue(&q) != value) {
                        is_queue = false;
                    } else {
                        dequeue(&q);
                    }
                }
                if (is_priority_queue) {
                    if (isPriorityQueueEmpty(&pq) || peekPQ(&pq) != value) {
                        is_priority_queue = false;
                    } else {
                        dequeuePQ(&pq);
                    }
                }
            }
        }
        int possible_count = is_stack + is_queue + is_priority_queue;
        if (possible_count == 0) {
            printf("impossible\n");
        } else if (possible_count > 1) {
            printf("not sure\n");
        } else {
            if (is_stack) printf("stack\n");
            else if (is_queue) printf("queue\n");
            else printf("priority queue\n");
        }
        free(s.arr);
        free(q.arr);
        free(pq.arr);
    }
    return 0;
}
