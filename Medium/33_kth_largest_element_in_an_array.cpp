/*
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n) - avg case, O(n^2) - worst case
Space complexity = O(1)
*/
class Solution {
private:
    static mt19937 rng;

    pair<int, int> threeWayPartition(vector<int>& nums, int low, int high) {
        int randInd = uniform_int_distribution<int>(low, high)(rng);
        int pivot = nums[randInd];
        int lt = low, i = low, gt = high;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i++], nums[lt++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
        return {lt, gt};
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int low = 0, high = n - 1;
        while (low <= high) {
            auto it = threeWayPartition(nums, low, high);
            auto lt = it.first, gt = it.second;
            if (target >= lt && target <= gt) {
                return nums[target];
            } else if (target < lt) {
                high = lt - 1;
            } else {
                low = gt + 1;
            }
        }
        return -1;
    }
};

mt19937 Solution::rng(chrono::steady_clock::now().time_since_epoch().count());
