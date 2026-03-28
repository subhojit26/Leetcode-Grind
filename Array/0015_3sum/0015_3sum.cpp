/*
 * Problem  : 15. 3Sum
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Sorting
 * URL      : https://leetcode.com/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r){
                vector<int> temp;
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                    ans.push_back(temp);
                }else if(sum>0){
                    r--;
                }else{
                    l++;
                }
                
            }
        }
        return ans;
    }
};