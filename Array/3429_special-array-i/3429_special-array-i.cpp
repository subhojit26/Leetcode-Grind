/*
 * Problem  : 3429. Special Array I
 * Difficulty: Easy
 * Topics   : Array
 * URL      : https://leetcode.com/problems/special-array-i/
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool res= true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2 != nums[i+1]%2){
                res = true;
            }else{
                res = false;
                break;
            }
        }
        return res;
    }
};