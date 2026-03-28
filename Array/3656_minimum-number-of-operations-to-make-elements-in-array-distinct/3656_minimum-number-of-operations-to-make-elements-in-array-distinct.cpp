/*
 * Problem  : 3656. Minimum Number of Operations to Make Elements in Array Distinct
 * Difficulty: Easy
 * Topics   : Array, Hash Table
 * URL      : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
 */

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> mp;
        int op=0;
        int ind=-1;
        for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            
            if(mp[nums[i]]>1){
                ind=i+1;
                break;
            }
        }
        if(ind==-1){
            return 0;
        }else{
            cout<<ind;
            op=ceil((double)ind/3.0);
            return op;
        }
    }
};