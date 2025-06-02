/*
Link: https://leetcode.com/problems/sliding-window-maximum/description/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n * log(k))
Space complexity = O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> m;
        for(int i=0; i<k; i++){
            m[nums[i]]++;
        }
        auto it = m.end();
        it--;
        ans.push_back(it->first);
        int i = 0, j = k;
        while(j < n){
            m[nums[i]]--;
            if(m[nums[i]] == 0) m.erase(nums[i]);
            m[nums[j]]++;
            it = m.end();
            it--;
            ans.push_back(it->first);
            i++, j++;
        }
        return ans;
    }
};