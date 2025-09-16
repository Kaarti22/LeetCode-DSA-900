/*
Link: https://leetcode.com/problems/ugly-number-ii/description/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n * logn)
Space complexity = O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> vis;
        pq.push(1LL);
        vis.insert(1LL);
        long long ans = -1;
        vector<int> factors = {2, 3, 5};
        while(!pq.empty()){
            long long val = pq.top();
            pq.pop();
            if(--n == 0){
                ans = val;
                break;
            }
            for(auto it: factors){
                if(vis.find(val * it) == vis.end()){
                    vis.insert(val * it);
                    pq.push(val * it);
                }
            }
        }
        return static_cast<int>(ans);
    }
};

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        for(int i=1; i<n; i++){
            int nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;
            if(nextUgly == next2){
                p2++;
                next2 = ugly[p2] * 2;
            }
            if(nextUgly == next3){
                p3++;
                next3 = ugly[p3] * 3;
            }
            if(nextUgly == next5){
                p5++;
                next5 = ugly[p5] * 5;
            }
        }
        return ugly[n-1];
    }
};