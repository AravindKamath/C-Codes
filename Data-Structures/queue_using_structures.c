#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int q[10];
    int front;
    int rear;
    int qsize;
};

void enqueue(struct Queue *ptr, int item) {
    ptr -> q[++(ptr -> rear)] = item;
}

int dequeue(struct Queue *ptr) {
    int item;
    item = ptr -> q[(ptr -> front)++];
    return item;
}

void display(struct Queue *ptr) {
    if (ptr -> front > ptr -> rear) {
        printf("\nQueue Empty\n");
    }
    else {
        printf("\nQueue Elements are: \n");
        for (int i = ptr -> front; i <= ptr -> rear; i++) {
            printf("%d\t", ptr -> q[i]);
        }
    }
}

void main() {
    struct Queue *ptr = (struct Queue*) malloc(sizeof(struct Queue));
    ptr -> front = 0;
    ptr -> rear = -1;
    ptr -> qsize = 5;
    int choice, item;
    while (1) {
        printf("\nEnter choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                if (ptr -> rear == (ptr -> qsize) - 1) {
                    printf("\nQueue Overflow\n");
                    break;
                }
                else {
                    printf("\nEnter item ");
                    scanf("%d", &item);
                    enqueue(ptr, item);
                    break;
                }
            case 2 :
                if (ptr -> front > ptr -> rear) {
                    printf("\nQueue Underflow\n");
                    break;
                }
                else {
                    item = dequeue(ptr);
                    printf("\n%d is removed\n", item);
                    break;
                }
            case 3 :
                display(ptr);
                break;
            case 4 : exit(0);
            default :
                printf("\nInvalid Input\n");
                break;
        }
    }
}
