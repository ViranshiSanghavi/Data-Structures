#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

bool isEmpty(struct Deque *deque) {
    return (deque->front == -1);
}

bool isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at front.\n");
    } else if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
        deque->items[deque->front] = data;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
        deque->items[deque->front] = data;
    }
}

void insertRear(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at rear.\n");
    } else if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
        deque->items[deque->rear] = data;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
        deque->items[deque->rear] = data;
    }
}

int deleteFront(struct Deque *deque) {
    int data = -1; // Default value for error or empty deque

    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
    } else if (deque->front == deque->rear) {
        data = deque->items[deque->front];
        deque->front = deque->rear = -1;
    } else {
        data = deque->items[deque->front];
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return data;
}

int deleteRear(struct Deque *deque) {
    int data = -1; // Default value for error or empty deque

    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
    } else if (deque->front == deque->rear) {
        data = deque->items[deque->rear];
        deque->front = deque->rear = -1;
    } else {
        data = deque->items[deque->rear];
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return data;
}

void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        int i = deque->front;
        printf("Deque elements: ");
        while (i != deque->rear) {
            printf("%d ", deque->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", deque->items[i]);
    }
}

int main() {
    struct Deque deque;
    deque.front = deque.rear = -1;

    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);

    display(&deque);

    printf("Deleted from front: %d\n", deleteFront(&deque));
    printf("Deleted from rear: %d\n", deleteRear(&deque));

    display(&deque);

    insertFront(&deque, 7);
    insertRear(&deque, 15);

    display(&deque);

    return 0;
}

/*Deque elements: 5 10 20
Deleted from front: 5
Deleted from rear: 20
Deque elements: 10
Deque elements: 7 10 15
*/

