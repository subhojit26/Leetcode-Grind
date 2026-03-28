/*
 * Problem  : 1537. Maximum Score After Splitting a String
 * Difficulty: Easy
 * Topics   : String, Prefix Sum
 * URL      : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 */

class Solution {
public:
    int maxScore(string s) {
        int len=s.length();
        int lp=0;
        int rp=len-1;
        int z=0,o=0,ans=INT_MIN;
        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                z++;
            }
        }
        o=len-z;
        int currZero=0;
        int currOne=0;
        for(int i=0;i<len-1;i++){
            if(s[i]=='0'){
                currZero++;
            }else{
                currOne++;
            }
            int leftScore=currZero;
            int rightScore=o-currOne;
            ans=max(ans,leftScore+rightScore);
        }
        
        return ans;
    }
};