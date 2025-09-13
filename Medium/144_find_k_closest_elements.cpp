/*
Link: https://leetcode.com/problems/find-k-closest-elements/description/

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = -1, right = n;
        for(int i=0; i<n; i++){
            if(arr[i] < x) left = i;
            else if(arr[i] == x){
                left = i;
                right = i + 1;
                break;
            } else {
                left = i - 1;
                right = i;
                break;
            }
        }
        vector<int> ans;
        while(ans.size() < k){
            if(left < 0){
                if(right >= n) break;
                ans.push_back(arr[right]);
                right++;
            } else if(right >= n){
                if(left < 0) break;
                ans.push_back(arr[left]);
                left--;
            } else {
                if(abs(arr[left] - x) <= abs(arr[right] - x)){
                    ans.push_back(arr[left]);
                    left--;
                } else {
                    ans.push_back(arr[right]);
                    right++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};