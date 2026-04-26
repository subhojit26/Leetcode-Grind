/*
 * Problem  : 34. Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution {
public:
    int findFirstOccur(vector<int> nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                res=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return res;
    }
    int findLastOccur(vector<int> nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        if(nums.size()==0){
            return {-1,-1};
        }
        int firstOccur=findFirstOccur(nums,target);
        int lastOccur=findLastOccur(nums,target);
        if(firstOccur<0 || firstOccur>=n || lastOccur<0 || lastOccur>=n){
            firstOccur=-1;
            lastOccur=-1;
        }
        ans.push_back(firstOccur);
        ans.push_back(lastOccur);
        return ans;
    }
};