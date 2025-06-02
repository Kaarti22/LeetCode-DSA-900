/*
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(log(min(n, m)))
Space complexity = O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = n;
        int half = (n + m + 1) / 2;
        while(left <= right){
            int i = left + (right - left) / 2;
            int j = half - i;
            int maxLeftA = (i == 0) ? INT_MIN : nums1[i-1];
            int minRightA = (i == n) ? INT_MAX : nums1[i];
            int maxLeftB = (j == 0) ? INT_MIN : nums2[j-1];
            int minRightB = (j == m) ? INT_MAX : nums2[j];
            if(maxLeftA <= minRightB && maxLeftB <= minRightA){
                if((n + m) % 2 == 0){
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if(maxLeftA > minRightB){
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};