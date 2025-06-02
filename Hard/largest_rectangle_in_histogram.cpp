/*
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int area = 0;
        for(int i=0; i<n; i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                area = max(area, (i - st.top().first) * st.top().second);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()){
            area = max(area, (n - st.top().first) * st.top().second);
            st.pop();
        }
        return area;
    }
};