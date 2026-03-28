/*
 * Problem  : 1524. String Matching in an Array
 * Difficulty: Easy
 * Topics   : Array, String, String Matching
 * URL      : https://leetcode.com/problems/string-matching-in-an-array/
 */

    //<---------------------Method 1------------------->//
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};