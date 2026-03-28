/*
 * Problem  : 3171. Minimum Equal Sum of Two Arrays After Replacing Zeros
 * Difficulty: Medium
 * Topics   : Array, Greedy
 * URL      : https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
 */

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int z1=0,z2=0,sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0){
                z1++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0){
                z2++;
            }
        }

        if(z1==0 && z2==0){
            return sum1==sum2?sum1:-1;
        }
        else if(z1==0){
            return sum2+z2<=sum1?sum1:-1;
        }
        else if(z2==0){
            return sum1+z1<=sum2?sum2:-1;
        }
        else{
            return max(sum1+z1,sum2+z2);
        }

    }
};