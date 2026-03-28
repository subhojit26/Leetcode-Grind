/*
 * Problem  : 2201. Valid Arrangement of Pairs
 * Difficulty: Hard
 * Topics   : Array, Depth-First Search, Graph Theory, Eulerian Circuit
 * URL      : https://leetcode.com/problems/valid-arrangement-of-pairs/
 */

class Solution {
public:
vector<vector<int>> findEulerianPath(vector<vector<int>> pairs, int maxNode){

    unordered_map<int,vector<int>>adjList;
    unordered_map<int,int> inDegree, outDegree;
    for(const auto &edge: pairs){
        int u=edge[0];
        int v=edge[1];
        adjList[u].push_back(v);
        outDegree[u]++;
        inDegree[v]++;
        //adjList[v].push_back(u);
    }

    int startNode=pairs[0][0];
    for(auto entry:adjList){
        int node=entry.first;
        if(outDegree[node]-inDegree[node]==1){
            startNode=node;
            break;
        }
    }

    stack<int> currPath;
    vector<int> eulerPath;

    currPath.push(startNode);
    while(!currPath.empty()){
        int node=currPath.top();
        if(!adjList[node].empty()){
            int next=adjList[node].back();
            adjList[node].pop_back();
            currPath.push(next);
        } else {
            eulerPath.push_back(node);
            currPath.pop();
        }
    }

    reverse(eulerPath.begin(),eulerPath.end());

    vector<vector<int>> res;

    for(int i=0;i<eulerPath.size()-1;i++){
        res.push_back({eulerPath[i],eulerPath[i+1]});
    }

    return res;

}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int maxNode=0;
        for(int i=0;i<pairs.size();i++){
            maxNode=max(maxNode,max(pairs[i][0],pairs[i][1]));
        }

        vector<vector<int>> ans=findEulerianPath(pairs,maxNode);
        return ans;

    }
};