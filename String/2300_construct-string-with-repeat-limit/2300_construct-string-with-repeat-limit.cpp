/*
 * Problem  : 2300. Construct String With Repeat Limit
 * Difficulty: Medium
 * Topics   : Hash Table, String, Greedy, Heap (Priority Queue), Counting
 * URL      : https://leetcode.com/problems/construct-string-with-repeat-limit/
 */

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        while (true) {
            bool added = false;

            // Try to add the largest available character
            for (int i = 25; i >= 0; --i) {
                if (freq[i] == 0) continue;

                // If this character is the same as the last in the result and we've reached the limit, skip
                if (!result.empty() && result.back() == ('a' + i) && result.length() >= repeatLimit && result.substr(result.length() - repeatLimit, repeatLimit) == string(repeatLimit, 'a' + i)) {
                    continue;
                }

                // Add up to repeatLimit of the current character
                int countToAdd = min(freq[i], repeatLimit);
                result.append(countToAdd, 'a' + i);
                freq[i] -= countToAdd;
                added = true;

                // If more characters of this type are left, add a break character
                if (freq[i] > 0) {
                    for (int j = i - 1; j >= 0; --j) {
                        if (freq[j] > 0) {
                            result.push_back('a' + j);
                            freq[j]--;
                            break;
                        }
                    }
                }
                break;
            }

            // If no character was added, we're done
            if (!added) break;
        }

        return result;
    }
};
