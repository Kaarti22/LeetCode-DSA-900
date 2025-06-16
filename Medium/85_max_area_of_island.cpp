/*
Link: https://leetcode.com/problems/max-area-of-island/description/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n*m)
Space complexity = O(n*m)
*/
class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis){
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        int c = 0;
        while(!q.empty()){
            c++;
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto d: dir){
                int newX = x + d[0], newY = y + d[1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && vis[newX][newY] == 0){
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
        return c;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans = max(ans, bfs(grid, i, j, vis));
                }
            }
        }
        return ans;
    }
};