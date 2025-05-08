#include <stdio.h>
#define max 5

void dfs(int graph[4][4], int visited[4], int node, int n) {
    printf("%d\t", node);
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {  
            dfs(graph, visited, i, n);
        }
    }
}

void bfs(int graph[4][4], int visited[4], int start, int n) {
    int queue[4];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int node = queue[front++];
        printf("%d\t", node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {  
                queue[rear++] = i;
                visited[i] = 1;
            } 
        }
    }

}

void main() {
    int graph[4][4] = 
    {{0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 0}};
    int visited[4] = {0, 0, 0, 0};
    dfs(graph, visited, 1, 4);
}