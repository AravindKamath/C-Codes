#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double value(char symbol, double op1, double op2) {
    switch(symbol) {
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '^' :
        case '$' : return pow(op1, op2);
        default : printf("Invalid symbol");
        exit(0);
    }
}

void postfix_evaluation(char exp[]) {
    double s[20], op1, op2, res;
    char symbol;
    int top = -1;
    for (int i = 0; i < strlen(exp); i++) {
        symbol = exp[i];
        if (isdigit(symbol)) {
            s[++top] = symbol - '0';
        }
        else {
            op2 = s[top--];
            op1 = s[top--];
            res = value(symbol, op1, op2);
            s[++top] = res;
        }
    }
    res = s[top--];
    printf("\nAnswer = %lf", res);

}

void main() {
    char exp[20];
    printf("Enter expression\n");
    scanf("%s", exp);
    //printf("%s", exp);
    postfix_evaluation(exp);
}

