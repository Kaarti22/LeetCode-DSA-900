/*
Link: https://leetcode.com/problems/surrounded-regions/description/

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
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

    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m){
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            board[x][y] = '#';
            for(auto d: dir){
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O' && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
                    bfs(i, j, board, vis, n, m);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};