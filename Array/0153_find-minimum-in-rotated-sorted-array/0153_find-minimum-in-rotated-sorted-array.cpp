/*
 * Problem  : 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            if(arr[mid]<arr[j]){
                j=mid;;
            }
            else {
                i=mid+1;
            }
        }
        return arr[i];
    }
};