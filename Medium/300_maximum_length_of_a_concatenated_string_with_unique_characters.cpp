/*
Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(2^n)
Space complexity = O(2^n)
*/
class Solution {
private:
    void dfs(vector<int>& masks, int ind, int currMask, int& ans){
        ans = max(ans, __builtin_popcount(currMask));
        for(int i=ind; i<masks.size(); i++){
            if((currMask & masks[i]) == 0){
                dfs(masks, i + 1, currMask | masks[i], ans);
            }
        }
    }

public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for(auto it: arr){
            int mask = 0;
            bool valid = true;
            for(auto ch: it){
                int bit = ch - 'a';
                if(mask & (1 << bit)){
                    valid = false;
                    break;
                }
                mask |= (1 << bit);
            }
            if(valid) masks.push_back(mask);
        }
        int ans = 0;
        dfs(masks, 0, 0, ans);
        return ans;
    }
};