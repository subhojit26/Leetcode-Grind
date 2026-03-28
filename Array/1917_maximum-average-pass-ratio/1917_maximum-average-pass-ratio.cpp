/*
 * Problem  : 1917. Maximum Average Pass Ratio
 * Difficulty: Medium
 * Topics   : Array, Greedy, Heap (Priority Queue)
 * URL      : https://leetcode.com/problems/maximum-average-pass-ratio/
 */

class Solution {
public:
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain=[](double pass, double total){
        return (pass+1)/(total+1)-pass/total;
    };
        priority_queue<pair<double, pair<int, int>>> pq;
        int n=classes.size();
        double sum=0.0;
        for(int i=0;i<n;i++){
            sum+=(double)classes[i][0]/(double)classes[i][1];
            pq.push({gain(classes[i][0],classes[i][1]),{classes[i][0],classes[i][1]}});
        }
        while(extraStudents--){
            int mini=pq.top().first;
            int pass=pq.top().second.first;
            int total=pq.top().second.second;
            pq.pop();

            sum-=(double)pass/(double)total;

            pass++;
            total++;
            pq.push({gain(pass,total),{pass,total}});
            sum+=(double)pass/(double)total;
        }
        return (double)sum/(double)n;
    }
};