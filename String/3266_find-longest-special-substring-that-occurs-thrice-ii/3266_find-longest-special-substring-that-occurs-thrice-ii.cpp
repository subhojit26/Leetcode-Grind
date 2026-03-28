/*
 * Problem  : 3266. Find Longest Special Substring That Occurs Thrice II
 * Difficulty: Medium
 * Topics   : Hash Table, String, Binary Search, Sliding Window, Counting
 * URL      : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/
 */

class Solution {
public:
    int maximumLength(string s) {
        int l=s.length();

        int mx=-1;
        vector<vector<int>> freq(26,vector<int> (l+1,0));
        for(int i=0, len=1;i<l;i++){
            char c=s[i];

            if(i>0 && s[i]==s[i-1]){
                len++;
            }
            else{
                len=1;
            }
            freq[c-'a'][len]++;
        }
        for(int i=0;i<26;i++){
            for(int j=l;j>0;j--){
                if(j<l){
                    freq[i][j]+=freq[i][j+1];
                }
                if(freq[i][j]>=3){
                    mx=max(mx,j);
                    break;
                }
            }
        }
        return mx;
    }
};