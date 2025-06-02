/*
Link: https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = 0;
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        maxRight[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int diff = min(maxLeft[i], maxRight[i]);
            if(diff > height[i]){
                ans += diff - height[i];
            }
        }
        return ans;
    }
};

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1, maxLeft = height[left], maxRight = height[right];
        int ans = 0;
        while(left < right){
            if(maxLeft <= maxRight){
                left++;
                ans += max(0, maxLeft - height[left]);
                maxLeft = max(maxLeft, height[left]);
            } else {
                right--;
                ans += max(0, maxRight - height[right]);
                maxRight = max(maxRight, height[right]);
            }
        }
        return ans;
    }
};