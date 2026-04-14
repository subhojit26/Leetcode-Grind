/*
 * Problem  : 399. Evaluate Division
 * Difficulty: Medium
 * Topics   : Array, String, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Shortest Path
 * URL      : https://leetcode.com/problems/evaluate-division/
 */

class Solution {
public:
    unordered_map<string,unordered_map<string,double>> buildGraph(vector<vector<string>> &equations, vector<double> &values){
        unordered_map<string,unordered_map<string,double>> gr;
        int n=equations.size();
        int m=equations[0].size();

        for(int i=0;i<n;i++){
            string dividend=equations[i][0];
            string divisor=equations[i][1];

            double value=values[i];
            gr[dividend][divisor]=value;
            gr[divisor][dividend]=1.0/value;
        }
        return gr;
    }

    void dfs(string source, string dest, unordered_map<string,unordered_map<string,double>> gr, unordered_set<string> &vis, double &res, double temp){
        if(vis.find(source)!=vis.end()){
            return;
        }

        vis.insert(source);

        if(source==dest){
            res=temp;
            return;
        }

        for(auto ne:gr[source]){
            dfs(ne.first,dest,gr,vis,res,temp*ne.second);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>>gr;
        gr=buildGraph(equations,values);
        vector<double> ans;
        int res=-1;
        for(auto it:queries){
            string dividend=it[0];
            string divisor=it[1];

            if(gr.find(dividend)==gr.end() || gr.find(divisor)==gr.end()){
                ans.push_back(-1);
            }
            else{
                unordered_set<string> vis;
                double res=-1,temp=1.0;
                dfs(dividend,divisor,gr,vis,res,temp);
                ans.push_back(res);
            }
        }
        return ans;
    }


};