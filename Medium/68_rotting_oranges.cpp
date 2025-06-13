/*
Link: https://leetcode.com/problems/rotting-oranges/description/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n*m)
Space complexity = O(n*m)
*/
class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        if(q.empty()){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1) return -1;
                }
            }
            return 0;
        }
        int time = -1;
        while(!q.empty()){
            time++;
            int size = q.size();
            for(int i=0; i<size; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto d: dir){
                    int newX = x + d[0], newY = y + d[1];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && vis[newX][newY] == 0){
                        vis[newX][newY] = 1;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};