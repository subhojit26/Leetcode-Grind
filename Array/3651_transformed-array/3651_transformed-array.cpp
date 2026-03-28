/*
 * Problem  : 3651. Transformed Array
 * Difficulty: Easy
 * Topics   : Array, Simulation
 * URL      : https://leetcode.com/problems/transformed-array/
 */

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int ind=i;
                int steps=nums[i];
                while(steps>0){
                    ind=(ind+1)%n;
                    steps--;
                }
                arr[i]=nums[ind];
            } else if(nums[i]<0){
                int ind=i;
                int steps=abs(nums[i]);
                while(steps>0){
                    ind=(ind-1+n)%n;
                    steps--;
                }
                arr[i]=nums[ind];
            } else{
                arr[i]=nums[i];
            }
        }
        return arr;
    }
};