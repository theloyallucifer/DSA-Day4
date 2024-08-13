#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Insert the element in queue: ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
        printf("%d is inserted in queue\n", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

