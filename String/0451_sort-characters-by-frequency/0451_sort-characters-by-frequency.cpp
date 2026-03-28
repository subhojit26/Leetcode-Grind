/*
 * Problem  : 451. Sort Characters By Frequency
 * Difficulty: Medium
 * Topics   : Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
 * URL      : https://leetcode.com/problems/sort-characters-by-frequency/
 */

// jai siya ram
class Solution {
public:
    static bool cmp(pair<char, int> p1, pair<char, int> p2) {
        // if(p1.second==p2.second){
        //     return p1.first<p2.first;
        // }
        //this is extra condition when frequency is same then sorting will be done based on keys 
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> freq(mpp.begin(), mpp.end());
        sort(freq.begin(), freq.end(), cmp);
        // applying comparator on vector
        // now i have sort the character based on decreasing frequency
        string ans = "";
        for (auto i : freq) {
            for (int j = 0; j < i.second; j++)
                ans += i.first;
        }
        return ans;
    }
};