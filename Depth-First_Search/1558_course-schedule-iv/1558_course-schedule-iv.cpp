/*
 * Problem  : 1558. Course Schedule IV
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * URL      : https://leetcode.com/problems/course-schedule-iv/
 */

class Solution {
public:
    void bfs(int i, vector<vector<bool>> &isReachable, vector<int> adjList[]){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int num=q.front();
            q.pop();

            for(auto it:adjList[num]){
                if(!isReachable[i][it]){
                    isReachable[i][it]=true;
                    q.push(it);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adjList[numCourses];
        for (const auto& prerequisite : prerequisites) {
            adjList[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses,false));
        vector<int> vis(numCourses, 0);       
        vector<int> pathVis(numCourses, 0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                bfs(i,isReachable,adjList);
            }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(isReachable[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};