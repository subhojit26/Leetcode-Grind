/*
 * Problem  : 41. First Missing Positive
 * Difficulty: Hard
 * Topics   : Array, Hash Table
 * URL      : https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=1;
        while(true){
            if(mp[count]>0){
                mp[count]--;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};