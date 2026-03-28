/*
 * Problem  : 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

class Solution {
public:
    int findMinIndex(vector<int> nums){
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]<nums[j]){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
    int binarySearch(vector<int> nums, int target){
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=(i+j)/2;

            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ind=findMinIndex(nums);

        vector<int> firstPart(nums.begin(), nums.begin() + ind);
        vector<int> secondPart(nums.begin() + ind, nums.end());

        int p1=-1,p2=-1;
        p1=binarySearch(firstPart,target);
        p2=binarySearch(secondPart,target);

        if(p1==-1 && p2==-1){
            return -1;
        }else if(p1!=-1){
            return p1;
        }else{
            return p2+ind;
        }
    }
};