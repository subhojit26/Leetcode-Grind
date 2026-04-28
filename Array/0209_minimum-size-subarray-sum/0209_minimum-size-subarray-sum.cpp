/*
 * Problem  : 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Sliding Window, Prefix Sum
 * URL      : https://leetcode.com/problems/minimum-size-subarray-sum/
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=0;
        int len=n+1;
        int sum=0;
        while(high<n){
            sum+=nums[high];
            cout<<low<<" "<<high<<"\n";
            if(sum>=target){
                
                while(sum>=target){
                    len=min(len,high-low+1);
                    sum-=nums[low];
                    low++;
                }
            }
            high++;
        }
        return (len==n+1)?0:len;
    }
};