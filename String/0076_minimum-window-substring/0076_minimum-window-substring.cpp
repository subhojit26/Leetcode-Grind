/*
 * Problem  : 76. Minimum Window Substring
 * Difficulty: Hard
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/minimum-window-substring/
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int ls=s.length();
        int lt=t.length();
        unordered_map<char, int> window;
        unordered_map<char, int> need;

        for(int i=0;i<lt;i++){
            need[t[i]]++;
        }
        int required=need.size();
        int l=0;
        int r=0;
        int res=INT_MAX;
        int count=0;
        int start=0;

        while(r<ls){
            char c=s[r];
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    count++;
                }
            }

            while(count==required){
                if(r-l+1<res){
                    start=l;
                    res=r-l+1;
                }

                char lChar=s[l];
                if(need.count(lChar)){
                    window[lChar]--;
                    if(window[lChar]<need[lChar]){
                        count--;
                    }
                }
                l++;
            }
            r++;
        }
        
        return res==INT_MAX?"":s.substr(start,res);
    }
};