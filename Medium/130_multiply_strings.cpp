/*
Link: https://leetcode.com/problems/multiply-strings/description/

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n*m)
Space complexity = O(n+m)
*/
class Solution {
private:
    string add(string& a, string& b){
        string ans = "";
        int n = a.size(), m = b.size();
        int carry = 0;
        int i = n - 1, j = m - 1;
        while(i >= 0 && j >= 0){
            int add = (a[i] - '0') + (b[j] - '0') + carry;
            carry = add / 10;
            int rem = add % 10;
            ans = to_string(rem) + ans;
            i--;
            j--;
        }
        while(i >= 0){
            int add = (a[i] - '0') + carry;
            carry = add / 10;
            int rem = add % 10;
            ans = to_string(rem) + ans;
            i--;
        }
        while(j >= 0){
            int add = (b[j] - '0') + carry;
            carry = add / 10;
            int rem = add % 10;
            ans = to_string(rem) + ans;
            j--;
        }
        if(carry > 0){
            ans = to_string(carry) + ans;
        }
        return ans;
    }

public:
    string multiply(string num1, string num2) {
        string ans = "";
        int n = num1.size(), m = num2.size();
        for(int i=m-1; i>=0; i--){
            int carry = 0;
            string temp = "";
            int b = num2[i] - '0';
            for(int j=n-1; j>=0; j--){
                int a = num1[j] - '0';
                int total = a * b + carry;
                carry = total / 10;
                int rem = total % 10;
                temp = to_string(rem) + temp;
            }
            if(carry > 0){
                temp = to_string(carry) + temp;
            }
            int shift = m - 1 - i;
            while(shift--){
                temp.push_back('0');
            }
            ans = add(ans, temp);
        }
        int pos = 0;
        while(pos < ans.size() && ans[pos] == '0') pos++;
        return pos == ans.size() ? "0" : ans.substr(pos);
    }
};