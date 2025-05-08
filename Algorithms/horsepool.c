#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[300];

void shift_table(char p[], int m, int *table) {
    for (int i = 0; i <= 256; i++) {
        table[i] = m;
    }
    for (int j = 0; j <= m - 2; j++) {
        table[p[j]] = m - 1 - j;
    }
}

int horsepools(char t[], char p[], int n, int m) {
    shift_table(p, m, table);
    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && p[m - 1 - k] == t[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        }
        else {
            i = i + table[t[i]];
        }
    }
    return -1;
}

void main() {
    char t[] = "QWERTYUIOP";
    int n = strlen(t);
    char p[] = "UIO";
    int m = strlen(p);
    int ans = horsepools(t, p, n, m);
    printf("%d", ans);
}