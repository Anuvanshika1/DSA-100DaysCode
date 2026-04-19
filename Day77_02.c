/*Critical Connections in a Network

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
*/

#include <stdio.h>
#include <stdlib.h>

int timer = 0;

// DFS
void dfs(int u, int parent, int* disc, int* low,
         int** graph, int* graphSize,
         int** result, int* returnSize, int* colSizes) {

    disc[u] = low[u] = ++timer;

    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, graphSize,
                result, returnSize, colSizes);

            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                colSizes[*returnSize] = 2;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {

    // Step 1: Count degrees
    int* graphSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        graphSize[connections[i][0]]++;
        graphSize[connections[i][1]]++;
    }

    // Step 2: Allocate exact memory
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(graphSize[i] * sizeof(int));
        graphSize[i] = 0; // reset for filling
    }

    // Step 3: Fill adjacency list
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    // Step 4: Initialize
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;

    // Step 5: DFS
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, disc, low, graph, graphSize,
                result, returnSize, *returnColumnSizes);
        }
    }

    return result;
}
