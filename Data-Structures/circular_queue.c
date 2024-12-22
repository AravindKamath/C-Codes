#include <stdio.h>
#include <stdlib.h>

int MAX = 4, front = 0, rear = -1, count = 0;

void enqueue(int Q[], int item) {
    count++;
    rear = (rear + 1) % MAX;
    Q[rear] = item;
}

int dequeue(int Q[]) {
    int item;
    count--;
    item = Q[front];
    front = (front + 1) % MAX;
    return item;
}

void show(int Q[]) {
    if (count == 0) {
        printf("Queue is Empty\n");
    }
    else {
        int temp = front;
        printf("Queue Elements are\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t", Q[temp]);
            temp = (temp + 1) % MAX;
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
                if (count == MAX) {
                    printf("\nQueue Overflow\n");
                    break;
                }
                else {
                    printf("\nEnter item\n");
                    scanf("%d", &item);
                    enqueue(Q, item);
                    break;
                }
            case 2 :
                if (count == 0) {
                    printf("Queue Underflow\n");
                    break;
                }
                else {
                    item = dequeue(Q);
                    printf("%d is removed from Queue\n", item);
                    break;
                }
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