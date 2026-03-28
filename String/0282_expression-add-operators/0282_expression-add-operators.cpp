/*
 * Problem  : 282. Expression Add Operators
 * Difficulty: Hard
 * Topics   : Math, String, Backtracking
 * URL      : https://leetcode.com/problems/expression-add-operators/
 */

class Solution {
public:
    void solver(int pos, long long eval, long long multed, string exp, int len, string num, int target, vector<string> &ans) {
        if (pos == len) {
            if (eval == target) {
                ans.push_back(exp);
            }
            return;
        }
        for (int i = pos; i < len; i++) {
            // Skip numbers that start with '0' and are not a single '0'
            if (i > pos && num[pos] == '0') break;

            long long cur = stol(num.substr(pos, i - pos + 1));
            string tempPath = num.substr(pos, i - pos + 1);  // The current number as a string

            if (pos == 0) {
                solver(i + 1, cur, cur, tempPath, len, num, target, ans);
            } else {
                solver(i + 1, eval + cur, cur, exp + "+" + tempPath, len, num, target, ans);
                solver(i + 1, eval - cur, -cur, exp + "-" + tempPath, len, num, target, ans);
                solver(i + 1, eval - multed + multed * cur, multed * cur, exp + "*" + tempPath, len, num, target, ans); 
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        int len = num.length();
        string exp = "";
        vector<string> ans;
        if (num == "" || len == 0) {
            return ans;
        }

        int pos = 0;
        long long eval = 0;
        long long multed = 0;

        solver(pos, eval, multed, exp, len, num, target, ans);  
        return ans;
    }
};
