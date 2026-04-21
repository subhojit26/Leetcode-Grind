/*
 * Problem  : 202. Happy Number
 * Difficulty: Easy
 * Topics   : Hash Table, Math, Two Pointers
 * URL      : https://leetcode.com/problems/happy-number/
 */

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        mp[n]=1;
        
        while(n!=1){
            int sum=0;
            int t=n;
            while(t){
                int r=t%10;
                sum+=r*r;
                t=t/10;
            }
            n=sum;
            if(mp[sum]==1){
                return false;
            }
            mp[sum]=1;
        }
        return true;
    }
};