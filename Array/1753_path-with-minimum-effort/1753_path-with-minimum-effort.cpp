/*
 * Problem  : 1753. Path With Minimum Effort
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
 * URL      : https://leetcode.com/problems/path-with-minimum-effort/
 */

struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        // Custom comparison logic:
        // First compare the outer int values, if they are equal, compare the inner pair values
        if (a.first == b.first) {
            if (a.second.first == b.second.first) {
                return a.second.second > b.second.second;  // Compare the second element of the inner pair
            }
            return a.second.first > b.second.first;  // Compare the first element of the inner pair
        }
        return a.first > b.first;  // Compare the outer int values
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int,pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> effort(n,vector<int> (m,1e9));

        effort[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int curr_effort=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1){
                return curr_effort;
            }

            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int new_effort=max(curr_effort,abs(heights[r][c]-heights[nr][nc]));
                    if(new_effort<effort[nr][nc]){
                        effort[nr][nc]=new_effort;
                        pq.push({new_effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};