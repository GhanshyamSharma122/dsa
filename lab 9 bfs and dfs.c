BFS IN A GRAPH
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int queue[100];
int front = -1, rear = -1;


int isEmpty() {
    return front == -1;
}

void push(int value) {
    if (rear == 99) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) { 
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}


void bfs(int graph[][100], int visited[], int n, int start) {

    visited[start] = 1;
    push(start);

    while (!isEmpty()) {
        int node = pop();
        printf("%d ", node);

        for (int i = 1; i <= n; i++) {  
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                push(i);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[100][100] = {0};
    int *visited = (int *)calloc(n + 1, sizeof(int));

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bfs(graph, visited, n, 1);

    return 0;
}
output:

DFS OF A GRAPH:
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>



void dfs(int graph[][100], int visited[], int n,int start) {
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 1; i < n+1; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(graph, visited,n,i);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n+1][n+1];
    int *visited=(int *)calloc(n+1,sizeof(int));
    printf("now enter the adjacency matrix:\n");
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    dfs(graph, visited, n,1);

    return 0;
}
