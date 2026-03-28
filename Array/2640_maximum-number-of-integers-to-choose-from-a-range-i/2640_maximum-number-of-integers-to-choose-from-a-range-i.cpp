/*
 * Problem  : 2640. Maximum Number of Integers to Choose From a Range I
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Binary Search, Greedy, Sorting
 * URL      : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
 */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int> mp;
        for(int i=0;i<banned.size();i++){
            mp[banned[i]]++;
        }
        int sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end() && sum+i<=maxSum){
                cnt++;
                sum=sum+i;
            } 
            if(sum>maxSum){
                break;
            }
        }
        return cnt;
    }
};