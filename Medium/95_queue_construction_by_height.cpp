/*
Link: https://leetcode.com/problems/queue-reconstruction-by-height/description/

You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^2)
Space complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int i = 0;
        while(i < n && people[i][1] == 0){
            i++;
        }
        while(i < n){
            int c = 0;
            int j = 0;
            while(j < n && c < people[i][1]){
                if(people[j][0] >= people[i][0]){
                    c++;
                }
                j++;
            }
            while(j < n && people[j][0] <= people[i][0]){
                j++;
            }
            vector<int> prev = people[i];
            while(j < i){
                vector<int> curr = people[j];
                people[j] = prev;
                prev = curr;
                j++;
            }
            people[i] = prev;
            i++;
        }
        return people;
    }
};