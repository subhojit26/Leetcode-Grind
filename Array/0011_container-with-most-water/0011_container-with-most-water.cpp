/*
 * Problem  : 11. Container With Most Water
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Greedy
 * URL      : https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmax=INT_MIN;
        int rmax=INT_MIN;
        int cap=0;
        while(l<=r){
            if(height[l]<height[r]){
                if(height[l]>lmax){
                    lmax=height[l];
                    cap=max(cap,min(height[l],height[r])*(r-l));
                }
                l++;
            }else{
                if(height[r]>rmax){
                    rmax=height[r];
                    cap=max(cap,min(height[l],height[r])*(r-l));
                }
                r--;
            }
        }
        return cap;
    }
};