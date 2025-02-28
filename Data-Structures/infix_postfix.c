#include<stdio.h>
#include<string.h>

int F(char symbol) {
    switch(symbol) {
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 4;
        case '$' :
        case '^' : return 5;
        case '(' : return 0;
        case '#' : return -1;
        default : return 8;
    }
}

int G(char symbol) {
    switch(symbol) {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 3;
        case '$' :
        case '^' : return 6;
        case '(' : return 9;
        case ')' : return 0;
        default : return 7;
    }
}

void infix_postfix(char infix[], char postfix[]) {
    char s[50], symbol;
    int top = -1, j = 0;
    s[++top] = '#';
    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        while (F(s[top]) > G(symbol)) {
            postfix[j++] = s[top--];
        }
        if (F(s[top]) != G(symbol)) {
             s[++top] = symbol;
        }
        else {
            //postfix[j++] = s[top--];
            top--;
        }
    }
    while (s[top] != '#') {
        postfix[j++] = s[top--];
        //postfix[j] = '\0';
    }
    printf("Postfix Form\n");
    printf("%s", postfix);
}

void main() {
    char infix[50], postfix[50];
    printf("Enter infix expression\n");
    scanf("%s", infix);
    infix_postfix(infix, postfix);
}