/*
Link: https://leetcode.com/problems/sort-characters-by-frequency/

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(52)
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto it: s){
            m[it]++;
        }
        vector<pair<char, int>> v;
        for(auto it: m){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), [&](pair<char, int>& p1, pair<char, int>& p2){
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        });
        string ans = "";
        for(auto it: v){
            while(it.second--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};