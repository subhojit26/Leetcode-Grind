/*
 * Problem  : 3629. Total Characters in String After Transformations I
 * Difficulty: Medium
 * Topics   : Hash Table, Math, String, Dynamic Programming, Counting
 * URL      : https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
 */

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        for(int i=1;i<=t;i++){
            vector<int> temp(26,0);
            for(int j=0;j<26;j++){
                char ch=j+'a';
                int freq=mp[j];
                if(ch!='z'){
                    temp[ch+1-'a']=(temp[ch+1-'a']+freq)%1000000007;
                }else{
                    temp[0]=(temp[0]+freq)%1000000007;
                    temp[1]=(temp[1]+freq)%1000000007;
                }
            }
            mp=temp;
        }
        for(auto it:mp){
            ans=(ans+it)%1000000007;
        }
        return ans;
    }
};