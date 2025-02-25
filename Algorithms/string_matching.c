#include <stdio.h>
#include <time.h>
#include <string.h>

void string_match(char *string, int n, char *pattern, int m) {
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (string[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Match is found at position %d\n", i);
            return;
        }
    }
    printf("Match is not found\n");
    return;
}

void main() {
    char string[] = "it is a beautiful day today";
    char pattern[] = "today";
    int n = strlen(string);
    int m = strlen(pattern);
    clock_t start = clock();
    string_match(string, n, pattern, m);
    clock_t end = clock();
    double cpu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f", cpu);
}