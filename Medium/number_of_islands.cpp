/*
Link: https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
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

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto it: dir){
                int newX = x + it[0], newY = y + it[1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && vis[newX][newY] == 0){
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};