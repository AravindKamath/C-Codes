#include <stdio.h>
int stack[4];
int k = -1;

void dfs(int graph[4][4], int visited[4], int node, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
    stack[++k] = node;
}

void main() {
    int graph[4][4] =
    {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    int visited[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, 4);
        }
    }
    for (int i = k; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
}