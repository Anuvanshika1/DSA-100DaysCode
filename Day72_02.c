/*Travelling Salesman Problem

Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104
*/

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int mask, int pos, vector<vector<int>>& cost){
        if(mask == (1 << n) - 1){
            return cost[pos][0]; 
        }

        if(dp[mask][pos] != -1){
            return dp[mask][pos];
        }

        int ans = INT_MAX;

        for(int city = 0; city < n; city++){
            if((mask & (1 << city)) == 0){
                int newAns = cost[pos][city] +
                             solve(mask | (1 << city), city, cost);
                ans = min(ans, newAns);
            }
        }

        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>>& cost){
        n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));

        return solve(1, 0, cost);
    }
};
