/*
 * Problem  : 3267. Find Longest Special Substring That Occurs Thrice I
 * Difficulty: Medium
 * Topics   : Hash Table, String, Binary Search, Sliding Window, Counting
 * URL      : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/
 */

class Solution {
public:
    int maximumLength(string s) {
        int l=s.length();
        map<string, int> mp;
        for(int i=0;i<l;i++){
            string curr;
            for(int j=i;j<l;j++){
                if(curr.empty() || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    mp[curr]++;
                }else{
                    break;
                }
            }
        }
        int mx=-1;
        for(auto [substr,count]:mp){
            if(count>=3){
                int l=substr.length();
                mx=max(mx,l);
            }
        }
        return mx;
    }
};