/*
Link: https://leetcode.com/problems/word-search/description/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n * m * 3^L)
Space complexity = O(L)
*/
class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& board, string& word, int ind, int x, int y){
        if(ind == word.size()) return true;
        int n = board.size(), m = board[0].size();
        char org = board[x][y];
        board[x][y] = '#';
        for(auto it: dir){
            int newX = x + it[0], newY = y + it[1];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == word[ind]){
                if(dfs(board, word, ind + 1, newX, newY)){
                    board[x][y] = org;
                    return true;
                }
            }
        }
        board[x][y] = org;
        return false;
    }    

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        if(word.size() > n * m) return false;
        unordered_map<char, int> freq;
        for(auto r: board){
            for(auto c: r){
                freq[c]++;
            }
        }
        for(auto ch: word){
            if(freq[ch]-- <= 0) return false;
        }
        int left = word[0], right = word.back();
        if(freq[left] > freq[right]){
            reverse(word.begin(), word.end());
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 1, i, j)) return true;
                }
            }
        }
        return false;
    }
};