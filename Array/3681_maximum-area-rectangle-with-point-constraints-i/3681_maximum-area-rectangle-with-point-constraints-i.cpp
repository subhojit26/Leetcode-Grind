/*
 * Problem  : 3681. Maximum Area Rectangle With Point Constraints I
 * Difficulty: Medium
 * Topics   : Array, Math, Binary Indexed Tree, Segment Tree, Geometry, Sorting, Enumeration
 * URL      : https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/
 */

class Solution {
public:
    struct ph {
    size_t operator()(const pair<int, int>& point) const {
        return hash<int>()(point.first) ^ hash<int>()(point.second);
    }
};
    int maxRectangleArea(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, ph> ps;
        for (auto& pt : points){
            ps.insert({pt[0], pt[1]});
        }
        int maxArea = -1;
        int n = points.size();
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 !=x2 && y1!= y2){
                    if (ps.count({x1, y2}) && ps.count({x2, y1})){
                        bool val =true;
                        for (auto& p: points) {
                            int px = p[0], py = p[1];
                            if ((px == x1&& py==y1)|| (px ==x1 && py ==y2)|| (px ==x2 && py==y1)|| (px == x2&&py ==y2)){
                                continue;
                            }
                            if (px >= min(x1, x2) && px <= max(x1, x2) && py >= min(y1, y2) && py <= max(y1, y2)){
                                val = false;
                                break;
                            }
                        }
                        if (val){
                            int area = abs(x2 - x1) * abs(y2 - y1);
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};