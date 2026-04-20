/*Articulation Point - I

Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:
Output:{1,4}
*/

#include <stdbool.h>
#include <stdlib.h>

int timeCounter;

void APUtil(int u, bool* visited, int* disc, int* low, int parent, bool* isAP, int V, List** adj) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < adj[u]->size; i++) {
        int v = adj[u]->arr[i];

        if (!visited[v]) {
            children++;
            APUtil(v, visited, disc, low, u, isAP, V, adj);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    if (parent == -1 && children > 1)
        isAP[u] = true;
}

int* articulationPoints(int V, List** adj, int* returnSize) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* isAP = (bool*)calloc(V, sizeof(bool));
    int* disc = (int*)malloc(V * sizeof(int));
    int* low = (int*)malloc(V * sizeof(int));

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            APUtil(i, visited, disc, low, -1, isAP, V, adj);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (isAP[i])
            count++;
    }

    if (count == 0) {
        int* ans = (int*)malloc(sizeof(int));
        ans[0] = -1;
        *returnSize = 1;
        return ans;
    }

    int* ans = (int*)malloc(count * sizeof(int));
    int idx = 0;

    for (int i = 0; i < V; i++) {
        if (isAP[i])
            ans[idx++] = i;
    }

    *returnSize = count;

    free(visited);
    free(isAP);
    free(disc);
    free(low);

    return ans;
}
