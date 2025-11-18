#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX]; 
int transpose[MAX][MAX]; 
int visited[MAX]; 
int stack[MAX]; 
int top = -1; 
int n; 

void push(int vertex) {
 stack[++top] = vertex;
}
int pop() {
 return stack[top--];
}

void dfsFillStack(int graph[MAX][MAX], int vertex) {
 visited[vertex] = 1;
 for (int i = 0; i < n; i++) {
 if (graph[vertex][i] && !visited[i]) {
 dfsFillStack(graph, i);
 }
 }

 push(vertex);
}

void dfsPrintSCC(int graph[MAX][MAX], int vertex) {
 printf("%d ", vertex); 
 visited[vertex] = 1;
 for (int i = 0; i < n; i++) {
 if (graph[vertex][i] && !visited[i]) {
 dfsPrintSCC(graph, i);
 }
 }
}

void transposeGraph() {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 transpose[i][j] = adj[j][i];
 }
 }
}

void findSCCs() {

 for (int i = 0; i < n; i++) {
 visited[i] = 0; 
 }
 for (int i = 0; i < n; i++) {
 if (!visited[i])
 dfsFillStack(adj, i);
 }

 transposeGraph();

 for (int i = 0; i < n; i++)
 visited[i] = 0; 
 printf("Strongly Connected Components:\n");
 while (top != -1) {
 int vertex = pop();
 if (!visited[vertex]) {
 dfsPrintSCC(transpose, vertex);
 printf("\n");
 }
 }
}
int main() {
 int edges, u, v;
 printf("Enter the number of vertices: ");
 scanf("%d", & n);

 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 adj[i][j] = 0;
 }
 }
 printf("Enter the number of edges: ");
 scanf("%d", & edges);
 printf("Enter the edges (u v):\n");
 for (int i = 0; i < edges; i++) {
 scanf("%d %d", & u, & v);
 adj[u][v] = 1;
 }
 findSCCs();
 return 0;
}
