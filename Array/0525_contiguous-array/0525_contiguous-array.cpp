/*
 * Problem  : 525. Contiguous Array
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Prefix Sum
 * URL      : https://leetcode.com/problems/contiguous-array/
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int>mp{{0,-1}};
        int sum=0;
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=(nums[i]==1)?1:-1;
            if(mp.find(sum)!=mp.end()){
                mx=max(mx,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return mx;
    }
};