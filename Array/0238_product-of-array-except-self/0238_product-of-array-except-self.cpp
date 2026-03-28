/*
 * Problem  : 238. Product of Array Except Self
 * Difficulty: Medium
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int p=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            p*=nums[i];
        }
        if(zero>1){
            vector<int> ans(n,0);
            return ans;
        }

        if(zero==1){
            vector<int> ans(n,0);
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=p;
                }
            }
            return ans;
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=p/nums[i];
        }
        return ans;
    }
};