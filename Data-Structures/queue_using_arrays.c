#include <stdio.h>
#include <stdlib.h>
int rear = -1;
int front = 0;
int MAX = 5;

void enqueue(int Q[], int item) {
    if (rear == MAX -1) {
        printf("Queue Overflow\n");
    }
    else {
        Q[++rear] = item;
    }
}

int dequeue(int Q[]) {
    int item;
    if (front > rear) {
        printf("Queue Underflow\n");
        return 0;
    }
    else {
        item = Q[front++];
        return item;
    }
}

void show(int Q[]) {
    if (front > rear) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Queue Elements are\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", Q[i]);
        }
    }
}

void main() {
    int Q[MAX], item, choice;
    while (1) {
        printf("\nEnter choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                printf("Enter item\n");
                scanf("%d", &item);
                enqueue(Q, item);
                break;
            case 2 :
                item = dequeue(Q);
                printf("%d is removed from Queue\n", item);
                break;
            case 3 :
                show(Q);
                break;
            case 4 :
                exit(0);
            default :
                printf("Invalid Choice\n");
                break;
        }
    }
}