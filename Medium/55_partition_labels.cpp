/*
Link: https://leetcode.com/problems/partition-labels/description/

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> m;
        for(int i=0; i<n; i++){
            m[s[i]].push_back(i);
        }
        vector<int> ans;
        int st = 0;
        while(st < n){
            char ch = s[st];
            int len = m[ch].size();
            int last = m[ch][len-1];
            int end = last;
            for(int i=st+1; i<end; i++){
                len = m[s[i]].size();
                last = m[s[i]][len-1];
                if(last > end){
                    end = last;
                }
            }
            ans.push_back(end - st + 1);
            st = end + 1;
        }
        return ans;
    }
};