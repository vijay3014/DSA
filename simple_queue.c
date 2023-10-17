#include <stdio.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int is_empty() {
    return front == -1;
}

// Function to check if the queue is full
int is_full() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

// Function to add an element to the rear of the queue
void enqueue(int value) {
    if (is_full()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (is_empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
        }
        queue[rear] = value;
    }
}

// Function to remove an element from the front of the queue
int dequeue() {
    if (is_empty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
        return value;
    }
}

// Function to display the elements in the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    int value = dequeue();
    if (value != -1) {
        printf("Dequeued element: %d\n", value);
    }

    display();

    return 0;
}
