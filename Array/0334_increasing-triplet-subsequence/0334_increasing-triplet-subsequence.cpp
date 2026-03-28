/*
 * Problem  : 334. Increasing Triplet Subsequence
 * Difficulty: Medium
 * Topics   : Array, Greedy
 * URL      : https://leetcode.com/problems/increasing-triplet-subsequence/
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=nums[0];
        int second=INT_MAX;
        int third=INT_MAX;
        bool tfound=false;
        bool sfound=false;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<first){
                cout<<"first= "<<nums[i]<<" ";
                first=nums[i];
            }
            else if(nums[i]>first){
                if(nums[i]<second){
                    cout<<"second= "<<nums[i]<<" ";
                    second=nums[i];
                    sfound=true;
                }else if(nums[i]>second){
                    cout<<"third= "<<nums[i]<<" ";
                    third=nums[i];
                    tfound=true;
                }
            }
        }
        if(tfound && sfound){
            return true;
        }
        return false;

    }
};