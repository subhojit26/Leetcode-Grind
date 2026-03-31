/*
 * Problem  : 162. Find Peak Element
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/find-peak-element/
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(n==1){
            return 0;
        }
        while(low<=high){
            int mid=(low+high)/2;
            cout<<low<<" "<<high<<" ";
            if(mid==0 && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(mid==n-1 && nums[mid]>nums[mid-1]){
                return mid;
            }
            if(mid>0 && mid<n && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid+1]>nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};