/* Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.


Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/

#include <stdlib.h>
#include <limits.h>

int min(int a, int b){
    return a < b ? a : b;
}

int absVal(int x){
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    int *minDist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        minDist[i] = INT_MAX;
    }
    
    minDist[0] = 0;  
    int result = 0;

    for(int i = 0; i < n; i++){
        int u = -1;

        for(int j = 0; j < n; j++){
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])){
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for(int v = 0; v < n; v++){
            if(!visited[v]){
                int dist = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    free(minDist);
    free(visited);
    
    return result;
}
