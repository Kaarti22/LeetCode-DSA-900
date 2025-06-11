/*
Link: https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(nlogn)
Space complexity = O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto it: nums){
            m[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(k--){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto it: nums){
            m[it]++;
        }
        int n = nums.size();
        vector<vector<int>> count(n+1, vector<int>());
        for(auto it: m){
            count[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n; i>0; i--){
            if(k == 0) break;
            if(count[i].size() > 0){
                for(int j=0; j<count[i].size() && k > 0; j++){
                    ans.push_back(count[i][j]);
                    k--;
                }
            }
        }
        return ans;
    }
};