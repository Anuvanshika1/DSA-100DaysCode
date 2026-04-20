/*Count Strongly Connected

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]
Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.

Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
*/


class Solution {
  public:
    
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(it, adj, vis, st);
            }
        }
        
        st.push(node); // store according to finishing time
    }
    
    void dfs2(int node, vector<vector<int>>& adjT, vector<int>& vis) {
        vis[node] = 1;
        
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs2(it, adjT, vis);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        // Step 2: DFS and fill stack
        vector<int> vis(V, 0);
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }
        
        // Step 3: Reverse the graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        
        // Step 4: DFS on reversed graph
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!vis[node]) {
                scc++;
                dfs2(node, adjT, vis);
            }
        }
        
        return scc;
    }
};
