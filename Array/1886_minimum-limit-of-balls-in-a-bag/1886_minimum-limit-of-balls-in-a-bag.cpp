/*
 * Problem  : 1886. Minimum Limit of Balls in a Bag
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
 */

class Solution {
public:
    bool isPossible(int maxBalls, vector<int> &nums, int maxOperations){
        int numOp=0;
        for(int i=0;i<nums.size();i++){
            numOp+=ceil((double)nums[i]/maxBalls)-1;
            if(numOp>maxOperations){
                return false;
            }
        }
        return true;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            r=max(r,nums[i]);
        }
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;

            if(isPossible(mid,nums,maxOperations)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};