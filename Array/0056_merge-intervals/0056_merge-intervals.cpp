/*
 * Problem  : 56. Merge Intervals
 * Difficulty: Medium
 * Topics   : Array, Sorting
 * URL      : https://leetcode.com/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int>res=intervals[0];
        
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=res[1]){
                res[1]=max(intervals[i][1],res[1]);
            }else{
                ans.push_back(res);
                res=intervals[i];
            }
        }
        ans.push_back(res);
        return ans;
    }
};