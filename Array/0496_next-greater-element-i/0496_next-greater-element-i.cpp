/*
 * Problem  : 496. Next Greater Element I
 * Difficulty: Easy
 * Topics   : Array, Hash Table, Stack, Monotonic Stack
 * URL      : https://leetcode.com/problems/next-greater-element-i/
 */

class Solution {
public:
    vector<int> findNGE(vector<int> nums){
        stack<int> st;
        vector<int> ans;
        int n=nums.size();

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top()>nums[i]){
                ans.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(st.top());
                }
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge=findNGE(nums2);
        // for(int i=0;i<nge.size();i++){
        //     cout<<nge[i]<<" ";
        // }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};