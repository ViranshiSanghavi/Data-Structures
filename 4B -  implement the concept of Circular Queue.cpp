#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

bool isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isFull(struct CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->items[queue->rear] = data;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = data;
    }
}

int dequeue(struct CircularQueue *queue) {
    int data = -1; // Default value for error or empty queue

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else if (queue->front == queue->rear) {
        data = queue->items[queue->front];
        queue->front = queue->rear = -1;
    } else {
        data = queue->items[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return data;
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Queue elements: ");
        while (i != queue->rear) {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    struct CircularQueue queue;
    queue.front = queue.rear = -1;

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    display(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    return 0;
}

/*Queue elements: 10 20 30
Dequeued: 10
Dequeued: 20
Queue elements: 30
Queue elements: 30 40 50
*/
