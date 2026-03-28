/*
 * Problem  : 42. Trapping Rain Water
 * Difficulty: Hard
 * Topics   : Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
 * URL      : https://leetcode.com/problems/trapping-rain-water/
 */

class Solution {
public:
    int trap(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        int lmax=0;
        int rmax=0;
        int water=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]<lmax){
                    water+=lmax-arr[l];
                }
                else{
                    lmax=arr[l];
                }
                l++;
            }
            else{
                if(arr[r]<rmax){
                    water+=rmax-arr[r];
                }
                else{
                    rmax=arr[r];
                }
                r--;
            }
        }
        return water;
    }
};