/*
 * Problem  : 1831. Ways to Split Array Into Three Subarrays
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Binary Search, Prefix Sum
 * URL      : https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
 */

class Solution {
public:
    int binarySearch(int ind, vector<int> &prefix, bool flag){
        int n=prefix.size();
        int left=ind+1;
        int right=n-2;
        int ans=-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            int leftSum=prefix[ind];
            int midSum=prefix[mid]-prefix[ind];
            int rightSum=prefix[n-1]-prefix[mid];

            if(midSum<leftSum){
                left=mid+1;
            }
            else if(rightSum<midSum){
                right=mid-1;
            }else{
                ans=mid;
                if(flag){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
        }
        return ans;
    }
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        long long int ans=0;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n-2;i++){
            int first=binarySearch(i,prefix,true);
            int last=binarySearch(i,prefix,false);

            if(first==-1 || last==-1){
                continue;
            }else{
                ans=(ans+(last-first+1))%1000000007;
            }
        }
        return ans;
    }
};