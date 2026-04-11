/*
 * Problem  : 452. Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Topics   : Array, Greedy, Sorting
 * URL      : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];  
        });
        int c=1;
        int l=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>l){
                c++;
                l=points[i][1];
            }
        }
        return c;
    }
};