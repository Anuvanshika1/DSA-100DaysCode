/* Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible
*/


#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int** adj, int* adjSize, int* state){
    if (state[node] == 1) return true;   
    if (state[node] == 2) return false; 
    state[node] = 1; 
    for(int i = 0; i < adjSize[node]; i++){
        int next = adj[node][i];
        if (dfs(next, adj, adjSize, state))
            return true;
    }

    state[node] = 2; 
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for(int i = 0; i < prerequisitesSize; i++){
        adjSize[prerequisites[i][1]]++;
    }

    for(int i = 0; i < numCourses; i++){
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; 
    }

    for(int i = 0; i < prerequisitesSize; i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    int* state = (int*)calloc(numCourses, sizeof(int));

    for(int i = 0; i < numCourses; i++){
        if (dfs(i, adj, adjSize, state))
            return false;
    }

    return true;
}
