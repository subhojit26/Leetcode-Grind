/*
 * Problem  : 4258. Construct Uniform Parity Array II
 * Difficulty: Medium
 * Topics   : Array, Math
 * URL      : https://leetcode.com/problems/construct-uniform-parity-array-ii/
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEven=INT_MAX;
        int minOdd=INT_MAX;

        bool allEven=true;
        bool allOdd=true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                minEven=min(minEven,nums1[i]);
            }else{
                minOdd=min(minOdd,nums1[i]);
            }
        }

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                if(nums1[i]<=minOdd){
                    allEven=false;
                }
            }else{
                if(nums1[i]<=minOdd){
                    allOdd=false;
                }
            }
        }
        return allEven||allOdd;
    }
};