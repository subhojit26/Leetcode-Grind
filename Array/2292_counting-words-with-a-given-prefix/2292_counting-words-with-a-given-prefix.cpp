/*
 * Problem  : 2292. Counting Words With a Given Prefix
 * Difficulty: Easy
 * Topics   : Array, String, String Matching
 * URL      : https://leetcode.com/problems/counting-words-with-a-given-prefix/
 */

class Solution {
    public:
        int prefixCount(vector<string>& words, string pref) {
                int count = 0;
                    for (const string& word : words) {
                            if (word.find(pref) == 0) { 
                                        count++;
                                                }
                                                    }
                                                        return count;
                                                            }
                                                            };



