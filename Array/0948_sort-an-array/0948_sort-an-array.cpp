/*
 * Problem  : 948. Sort an Array
 * Difficulty: Medium
 * Topics   : Array, Divide and Conquer, Sorting, Heap (Priority Queue), Merge Sort, Bucket Sort, Radix Sort, Counting Sort
 * URL      : https://leetcode.com/problems/sort-an-array/
 */

class Solution {
public:
    void helper(vector<int> &nums, int low, int mid, int high){
        int l1=low;
        int l2=mid+1;
        int h1=mid;
        int h2=high;
        vector<int> temp;
        while(l1<=h1 && l2<=h2){
            if(nums[l1]<nums[l2]){
                temp.push_back(nums[l1]);
                l1++;
            }
            else{
                temp.push_back(nums[l2]);
                l2++;
            }
        }
        while(l1<=h1){
            temp.push_back(nums[l1]);
            l1++;
        }
        while(l2<=h2){
            temp.push_back(nums[l2]);
            l2++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }

    }
    void solver(vector<int> & nums, int low, int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        solver(nums,low,mid);
        solver(nums,mid+1,high);
        helper(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        solver(nums,low,high);
        return nums;
    }
};

