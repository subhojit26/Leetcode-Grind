/*
 * Problem  : 1975. Minimum Distance to the Target Element
 * Difficulty: Easy
 * Topics   : Array
 * URL      : https://leetcode.com/problems/minimum-distance-to-the-target-element/
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                res=min(res,abs(start-i));
            }
        }
        return res;
    }
};