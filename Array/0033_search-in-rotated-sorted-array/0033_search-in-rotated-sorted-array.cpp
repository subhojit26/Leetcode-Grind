/*
 * Problem  : 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

class Solution {
public:
    int binarySearch(vector<int> nums, int low, int high, int target){
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ind;
        while(low<=high){
            int mid=(low+high)/2;

            if(mid>0 && mid<n-1 && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                ind=mid;
                break;
            }else if(nums[mid]>nums[n-1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        int res1=binarySearch(nums,ind,n-1,target);
        int res2=binarySearch(nums,0,ind-1,target);
        if(res1!=-1){
            return res1;
        }
        if(res2!=-1){
            return res2;
        }
        return -1;
    }
};