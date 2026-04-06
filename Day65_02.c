/*Undirected Graph Cycle

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
*/

#include <stdbool.h>
#include <stdlib.h>

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    parent[px] = py;
}

bool isCycle(int edges[][2], int E, int V) {
    int *parent = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu == pv)
            return true;

        unionSet(parent, pu, pv);
    }

    return false;
}
