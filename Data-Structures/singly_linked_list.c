#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Node not created\n");
        return NULL;
    }
    else {
        return temp;
    }
}

void display(NODE first) {
    int count = 0;
    NODE cur = first;
    if (cur == NULL) {
        printf("\nLinked List Empty\n");
        return;
    }
    printf("\nLinked List Elements\n");
    while (cur != NULL) {
        printf("[%d]\t", cur->data);
        cur = cur->next;
        count++;
    }
    printf("\nNumber of Nodes = %d\n", count);
}

NODE insertatfirst(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    if (first == NULL) {
        return temp;
    }
    else {
        temp->next = first;
        return temp;
    }
}

NODE deleteatfirst(NODE first) {
    if (first == NULL) {
        printf("\nLinked List Empty\n");
        return NULL;
    }
    else if (first->next == NULL) {
        printf("\n[%d] deleted\n", first->data);
        free(first);
        return NULL;
    }
    else {
        printf("\n[%d] deleted\n", first->data);
        first = first->next;
        return first;
    }
}

NODE insertatend(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    if (first == NULL) {
        return temp;
    }
    else {
        NODE cur = first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = NULL;
        return first;
    }
}

NODE deleteatend(NODE first) {
    if (first == NULL) {
        printf("\nList Empty\n");
        return NULL;
    }
    else if (first->next == NULL) {
        printf("\n[%d] deleted\n", first->data);
        free(first);
        return NULL;
    }
    else {
        NODE cur = first;
        NODE prev = NULL;
        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        printf("\n[%d] deleted\n", cur->data);
        prev->next = NULL;
        return first;
    }
}

NODE insertatindex(NODE first, int item, int pos) {
    NODE temp = getnode();
    temp->data = item;
    temp->next = NULL;
    if (first == NULL && pos == 1) {
        return temp;
    }
    if (first == NULL) {
        printf("Invalid Position\n");
        return NULL;
    }
    if (pos == 1) {
        temp->next = first;
        return temp;
    }
    int count = 1;
    NODE cur = first;
    NODE prev = NULL;
    while (cur != NULL && count != pos) {
        prev = cur;
        cur = cur->next;
        count++;
    }
    if (count == pos) {
        prev->next = temp;
        temp->next = cur;
        return first;
    }
    printf("Invalid Position\n");
    return first;
}

NODE deleteatindex(NODE first, int pos) {
    if (first == NULL) {
        printf("Empty List\n");
        return NULL;
    }
    if (pos == 1) {
        printf("[%d] deleted\n", first->data);
        first = first->next;
        return first;
    }
    NODE cur = first;
    NODE prev = NULL;
    int count = 1;
    while (cur != NULL && count != pos) {
        prev = cur;
        cur = cur->next;
        count++;
    }
    if (cur == NULL) {
        printf("Invalid Position\n");
        return first;
    }
    printf("[%d] deleted\n", cur->data);
    prev->next = cur->next;
    free(cur);
    return first;
}

NODE deletewithinfo(NODE first, int item) {
    if (first == NULL) {
        printf("Empty List\n");
        return NULL;
    }
    if (first->data == item) {
        printf("[%d] deleted in Position 1\n");
        first = first->next;
        return first;
    }
    NODE cur = first;
    NODE prev = NULL;
    int pos = 1;
    while (cur != NULL && cur->data != item) {
        prev = cur;
        cur = cur->next;
        pos++;
    }
    if (cur == NULL) {
        printf("Invalid Item\n");
        return first;
    }
    printf("[%d] deleted in Position %d", cur->data, pos);
    prev->next = cur->next;
    return first;
}

void main() {
    NODE first = NULL;

    first = insertatindex(first, 10, 1);
    first = insertatindex(first, 20, 2);
    first = insertatindex(first, 15, 2);
    display(first);

    first = deletewithinfo(first, 20);
    display(first);
}