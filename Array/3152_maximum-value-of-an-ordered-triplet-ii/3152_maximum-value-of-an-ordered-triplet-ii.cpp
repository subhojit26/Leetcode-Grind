/*
 * Problem  : 3152. Maximum Value of an Ordered Triplet II
 * Difficulty: Medium
 * Topics   : Array
 * URL      : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
 */

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefMax(n,0);
        vector<int> suffMax(n,0);
        long long maxi=0;
        for(int i=0;i<n-1;i++){
            prefMax[i+1]=max(prefMax[i],nums[i]);
            suffMax[n-2-i]=max(suffMax[n-i-1],nums[n-i-1]);
        }
        for(int i=1;i<n-1;i++){
            maxi=max(maxi,(long long)(prefMax[i]-nums[i])*suffMax[i]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<prefMax[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<suffMax[i]<<" ";
        // }
        return maxi;
    }
};