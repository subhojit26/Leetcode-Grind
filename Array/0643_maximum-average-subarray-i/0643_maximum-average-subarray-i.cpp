/*
 * Problem  : 643. Maximum Average Subarray I
 * Difficulty: Easy
 * Topics   : Array, Sliding Window
 * URL      : https://leetcode.com/problems/maximum-average-subarray-i/
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        double mx=-DBL_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1==k){
                cout<<mx<<" ";
                mx=max(mx,(double)sum/(double)k);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};