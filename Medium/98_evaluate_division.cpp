/*
Link: https://leetcode.com/problems/evaluate-division/description/

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(E + Q(V + E))
Space complexity = O(E + V)
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for(int i=0; i<n; i++){
            string u = equations[i][0], v = equations[i][1];
            double wt = values[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1.0 / wt});
        }
        n = queries.size();
        vector<double> ans(n);
        for(int i=0; i<n; i++){
            string u = queries[i][0], v = queries[i][1];
            queue<pair<string, double>> q;
            q.push({u, 1.0});
            unordered_set<string> vis;
            vis.insert(u);
            double finalValue = -1.0;
            while(!q.empty()){
                string node = q.front().first;
                double currVal = q.front().second;
                q.pop();
                if(adj.find(node) == adj.end()) break;
                if(node == v){
                    finalValue = currVal;
                    break;
                }
                for(auto it: adj[node]){
                    string adjNode = it.first;
                    double wt = it.second;
                    if(vis.find(adjNode) == vis.end()){
                        vis.insert(adjNode);
                        q.push({adjNode, currVal * wt});
                    }
                }
            }
            ans[i] = finalValue;
        }
        return ans;
    }
};