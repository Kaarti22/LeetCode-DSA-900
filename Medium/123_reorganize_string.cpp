/*
Link: https://leetcode.com/problems/reorganize-string/description/

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(nlogn)
Space complexity = O(n)
*/
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(auto it: s){
            m[it]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            if(ans.empty() || ans.back() != ch){
                ans.push_back(ch);
                if(--count > 0) pq.push({count, ch});
            } else {
                if(pq.empty()) return "";
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                ans.push_back(nextChar);
                if(--nextCount > 0) pq.push({nextCount, nextChar});
                pq.push({count, ch});
            }
        }
        return ans;
    }
};