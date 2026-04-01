/*
 * Problem  : 435. Non-overlapping Intervals
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy, Sorting
 * URL      : https://leetcode.com/problems/non-overlapping-intervals/
 */

class Solution {
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];  // sort by second element
    });
        vector<int> current = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < current[1]){
                ans++;
            }
            else{
                current = intervals[i];
            }
        }
        return ans;
    }
};

