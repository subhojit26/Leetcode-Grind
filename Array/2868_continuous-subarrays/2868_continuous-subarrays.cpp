/*
 * Problem  : 2868. Continuous Subarrays
 * Difficulty: Medium
 * Topics   : Array, Queue, Sliding Window, Heap (Priority Queue), Ordered Set, Monotonic Queue
 * URL      : https://leetcode.com/problems/continuous-subarrays/
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> freq;
        int right=0;
        int left=0;
        long long count=0;
        while(right<nums.size()){
            freq[nums[right]]++;
            while(freq.rbegin()->first-freq.begin()->first>2){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};