/*
 * Problem  : 2651. Count Ways to Group Overlapping Ranges
 * Difficulty: Medium
 * Topics   : Array, Sorting
 * URL      : https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
    int countWays(vector<vector<int>>& ranges) 
    {
        vector<vector<int>> ans= merge(ranges);
        if(ans.size()==1)
        {
            return 2;
        }
        else
        {
            long long int res=ans.size();
            long long int tes=2;
            while(res>1)
            {
                tes=(tes*2)%1000000007;
                res--;
            }
            return tes;
        }
    }
};