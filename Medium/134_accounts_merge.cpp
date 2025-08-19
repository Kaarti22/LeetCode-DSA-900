/*
Link: https://leetcode.com/problems/accounts-merge/description/

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(mlogm), where m = total number of emails
Space complexity = O(m + n), where n = number of accounts
*/
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int a, int b){
        int ulp_a = findUPar(a);
        int ulp_b = findUPar(b);
        if(ulp_a == ulp_b) return;
        if(size[ulp_a] < size[ulp_b]){
            parent[ulp_a] = ulp_b;
            size[ulp_b] += size[ulp_a];
        } else {
            parent[ulp_b] = ulp_a;
            size[ulp_a] += size[ulp_b];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mapMailNode.find(email) == mapMailNode.end()){
                    mapMailNode[email] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[email]);
                }
            }
        }
        vector<vector<string>> groupedAccounts(n);
        for(auto it: mapMailNode){
            string email = it.first;
            int node = it.second;
            int ulp = ds.findUPar(node);
            groupedAccounts[ulp].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(groupedAccounts[i].empty()) continue;
            sort(groupedAccounts[i].begin(), groupedAccounts[i].end());
            vector<string> account;
            string name = accounts[i][0];
            account.push_back(name);
            account.insert(account.end(), groupedAccounts[i].begin(), groupedAccounts[i].end());
            ans.push_back(account);
        }
        return ans;
    }
};