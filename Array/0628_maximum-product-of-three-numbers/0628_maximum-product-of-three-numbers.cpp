/*
 * Problem  : 628. Maximum Product of Three Numbers
 * Difficulty: Easy
 * Topics   : Array, Math, Sorting
 * URL      : https://leetcode.com/problems/maximum-product-of-three-numbers/
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1=INT_MIN, m2=INT_MIN, m3=INT_MIN;
        int n1=INT_MAX, n2=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>m1){
                m3=m2;
                m2=m1;
                m1=nums[i];
            }else if(nums[i]>m2){
                m3=m2;
                m2=nums[i];
            }else if(nums[i]>m3){
                m3=nums[i];
            }

            if(nums[i]<n1){
                n2=n1;
                n1=nums[i];
            }else if(nums[i]<n2){
                n2=nums[i];
            }
        }
        int p1=m1*m2*m3;
        int p2=n1*n2*m1;
        return max(p1,p2);
    }
};