/*
 * Problem  : 724. Find Pivot Index
 * Difficulty: Easy
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/find-pivot-index/
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> rsum(n+1,0);
        vector<int> lsum(n+1,0);
        int l=0,r=0;

        for(int i=0;i<n;i++){
            l+=nums[i];
            lsum[i+1]=l;
        }
        
        for(int i=n-1;i>0;i--){
            r+=nums[i];
            rsum[i-1]=r;
        }
        
        for(int i=0;i<=n;i++){
            cout<<lsum[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(lsum[i]==rsum[i]){
                return i;
            }
        }
        return -1;
    }
};

// 1 7 3 6 5 6

// 1 8 11 17 22 28
// 28 27 20 17 11 6

// lsum= 0 1 8 11 17 22 28
// rsum= 28 27 20 17 11 6 0

