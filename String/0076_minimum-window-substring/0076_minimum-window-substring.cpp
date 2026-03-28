/*
 * Problem  : 76. Minimum Window Substring
 * Difficulty: Hard
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/minimum-window-substring/
 */

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        int i=0;
        int j=0;
        int ls=s.length();
        int lt=t.length();
        int start=0;
        int minLen=INT_MAX;
        for(int i=0;i<lt;i++){
            mp[t[i]]++;
        }
        int count=mp.size();
        while(j<ls){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            while(count==0){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                        if(j-i+1<minLen){
                            minLen=j-i+1;
                            start=i;
                        }
                    }
                }
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};