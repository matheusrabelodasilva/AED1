#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node *front, *rear;
} Queue;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Queue* baralho = createQueue();
        int discarded_cards[50];
        int discarded_count = 0;
        for (int i = 1; i <= n; i++) {
            enqueue(baralho, i);
        }
        while (baralho->front->next != NULL) {
            discarded_cards[discarded_count++] = dequeue(baralho);
            int carta_a_mover = dequeue(baralho);
            enqueue(baralho, carta_a_mover);
        }
        printf("Discarded cards:");
        for (int i = 0; i < discarded_count; i++) {
            if (i == 0) {
                printf(" %d", discarded_cards[i]);
            } else {
                printf(", %d", discarded_cards[i]);
            }
        }
        printf("\n");
        printf("Remaining card: %d\n", baralho->front->data);
        free(baralho->front);
        free(baralho);
    }
    return 0;
}
