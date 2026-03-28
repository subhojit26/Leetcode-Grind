/*
 * Problem  : 3685. Count Subarrays of Length Three With a Condition
 * Difficulty: Easy
 * Topics   : Array
 * URL      : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
 */

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n =nums.size();
        int count=0;

        for (int i = 0;i<=n-3;i++){
            int first=nums[i];
            int middle=nums[i+1];
            int third=nums[i+2];

            if(first+third==middle/2.0){
                count++;
            }
        }

        return count;
    }
};
