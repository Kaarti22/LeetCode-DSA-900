/*
Link: https://leetcode.com/problems/valid-sudoku/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(81 + 81 + 81) * O(9) => O(1)
Space complexity = O(10) => O(1)
*/
class Solution {
private:
    bool check(vector<int>& hsh){
        for(int i=1; i<=9; i++){
            if(hsh[i] > 1) return true;
        }
        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> hsh;
        for(int i=0; i<9; i++){
            hsh.assign(10, 0);
            for(int j=0; j<9; j++){
                if(board[i][j] != '.') hsh[board[i][j] - '0']++;
            }
            if(check(hsh)) return false;
        }
        for(int j=0; j<9; j++){
            hsh.assign(10, 0);
            for(int i=0; i<9; i++){
                if(board[i][j] != '.') hsh[board[i][j] - '0']++;
            }
            if(check(hsh)) return false;
        }
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                hsh.assign(10, 0);
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(board[k][l] != '.') hsh[board[k][l] - '0']++;
                    }
                }
                if(check(hsh)) return false;
            }
        }
        return true;
    }
};