/*
Link: https://leetcode.com/problems/01-matrix/description/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
 

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(m*n)
Space complexity = O(m*n)
*/
class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<tuple<int, int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }
        while(!q.empty()){
            auto [dist, x, y] = q.front();
            q.pop();
            for(auto it: dir){
                int newX = x + it[0], newY = y + it[1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 1 && ans[newX][newY] == -1){
                    ans[newX][newY] = dist + 1;
                    q.push({dist + 1, newX, newY});
                }
            }
        }
        return ans;
    }
};