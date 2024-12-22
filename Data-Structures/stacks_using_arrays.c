#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
int top = -1;


void push(int arr[10], int item) {
    arr[++top] = item;
}

int pop(int arr[10]) {
    int item = arr[top--];
    return item;
}

void display(int arr[10]) {
    if (top == -1) {
        printf("\nStack is Empty\n");
    }
    else {
        printf("\nStack Elements are\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", arr[i]);
        }
    }
}

void main() {
    int arr[MAX], choice, item;
    while (true) {
        printf("\nEnter you choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                if (top == MAX - 1) {
                    printf("\nStack Overflow\n");
                    break;
                }
                else {
                    printf("\nEnter item to be pushed\n");
                    scanf("%d", &item);
                    push(arr, item);
                    break;
                }
            case 2 :
                if (top == -1) {
                    printf("\nStack Underflow\n");
                    break;
                }
                else {
                    item = pop(arr);
                    printf("\n%d is popped\n", item);
                    break;
                }
            case 3 :
                display(arr);
                break;
            case 4 :
                exit(0);
                break;
            default :
                printf("\nInvalid input\n");
                exit(0);
                break;
        }
    }
}