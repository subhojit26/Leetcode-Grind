/*
 * Problem  : 410. Split Array Largest Sum
 * Difficulty: Hard
 * Topics   : Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum
 * URL      : https://leetcode.com/problems/split-array-largest-sum/
 */

class Solution {
public:
    bool isPossible(int maxi, vector<int> nums, int k){
        int grp=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi){
                sum=nums[i];
                grp++;
            }
            if(grp>k){
                return false;
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int res=-1;
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<=right){
            int mid=(left+right)/2;
            if(isPossible(mid,nums,k)){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};