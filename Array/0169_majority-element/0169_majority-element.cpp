/*
 * Problem  : 169. Majority Element
 * Difficulty: Easy
 * Topics   : Array, Hash Table, Divide and Conquer, Sorting, Counting
 * URL      : https://leetcode.com/problems/majority-element/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int freq=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                freq++;
            }else{
                freq--;
            }
            if(freq<0){
                ele=nums[i];
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                c++;
            }
        }
        if(c>n/2){
            return ele;
        }
        return -1;
    }
};