/*
 * Problem  : 4256. Construct Uniform Parity Array I
 * Difficulty: Easy
 * Topics   : Array, Math
 * URL      : https://leetcode.com/problems/construct-uniform-parity-array-i/
 */

class Solution {
public:
    bool allOdd(vector<int> nums1, vector<int> nums2){
        int n=nums1.size();
        for(int i=0;i<n;i++){
            bool found=false;
            if(nums1[i]%2!=0){
                nums2[i]=nums1[i];
            }else{
                for(int j=0;j<n;j++){
                    if(i!=j && (nums1[i]-nums1[j])%2!=0){
                        nums2[i]=nums1[i]-nums1[j];
                        found=true;
                    }
                }
                if(!found){
                    return false;
                }
            }
        }
        return true;
    }
    bool allEven(vector<int> nums1, vector<int> nums2){
        int n=nums1.size();
        for(int i=0;i<n;i++){
            bool found=false;
            if(nums1[i]%2==0){
                nums2[i]=nums1[i];
            }else{
                for(int j=0;j<n;j++){
                    if(i!=j && (nums1[i]-nums1[j])%2==0){
                        nums2[i]=nums1[i]-nums1[j];
                        found=true;
                    }
                }
                if(!found){
                    return false;
                }
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> nums2(n,0);
        bool case1=allOdd(nums1,nums2);
        bool case2=allEven(nums1,nums2);
        return case1||case2;
    }
};