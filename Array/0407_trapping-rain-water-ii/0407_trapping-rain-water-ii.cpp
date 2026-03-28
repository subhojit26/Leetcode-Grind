/*
 * Problem  : 407. Trapping Rain Water II
 * Difficulty: Hard
 * Topics   : Array, Breadth-First Search, Heap (Priority Queue), Matrix
 * URL      : https://leetcode.com/problems/trapping-rain-water-ii/
 */

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                   greater<>> mh;
    int n=heightMap.size();
    int m=heightMap[0].size();
    vector<vector<int>> vis(n+1, vector<int> (m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                mh.push({heightMap[i][j],{i,j}});
                vis[i][j]=1;
            }
        }
    }
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    int water=0;

    while(!mh.empty()){
        int val=mh.top().first;
        int r=mh.top().second.first;
        int c=mh.top().second.second;
        mh.pop();

        for(int i=0;i<4;i++){
            int nr=r+delRow[i];
            int nc=c+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                if(heightMap[nr][nc]<val){
                    water+=val-heightMap[nr][nc];
                    mh.push({val,{nr,nc}});
                }else{
                    mh.push({heightMap[nr][nc],{nr,nc}});
                }
                vis[nr][nc]=1;
            }
        }
    }
        return water;

    }
    
};