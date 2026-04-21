/*
 * Problem  : 383. Ransom Note
 * Difficulty: Easy
 * Topics   : Hash Table, String, Counting
 * URL      : https://leetcode.com/problems/ransom-note/
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.find(ransomNote) != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
};