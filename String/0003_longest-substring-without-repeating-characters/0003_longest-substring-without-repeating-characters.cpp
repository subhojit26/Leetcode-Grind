/*
 * Problem  : 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int mx=0;
        int l=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            if(mp[s[i]]==1){
               
                mx=max(mx,i-l+1);
            }else{
                while(mp[s[i]]>1){
                    mp[s[l]]--;
                    l++;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                }
            }
            
        }
        return mx;
    }
};