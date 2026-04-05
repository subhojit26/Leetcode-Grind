/*
 * Problem  : 2553. Total Cost to Hire K Workers
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Heap (Priority Queue), Simulation
 * URL      : https://leetcode.com/problems/total-cost-to-hire-k-workers/
 */

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int, vector<int>, greater<int>> head_workers;
        long long cost=0;
        for(int i=0;i<candidates;i++){
            head_workers.push(costs[i]);
        }
        priority_queue<int, vector<int>, greater<int>> tail_workers;
        for(int i=n-1;i>=n-candidates;i--){
            tail_workers.push(costs[i]);
        }
        int next_head=candidates;
        int next_tail=n-candidates-1;

        while(k--){
            int head=head_workers.top();
            int tail=tail_workers.top();
            cout<<head<<" "<<tail<<" ";
            if(head<=tail){
                head_workers.pop();
                cost+=head;
                if(next_head<=next_tail){
                    head_workers.push(costs[next_head]);
                    next_head++;
                }
            }else{
                tail_workers.pop();
                cost+=tail;
                if(next_head<=next_tail){
                    tail_workers.push(costs[next_tail]);
                    next_tail--;
                }
            }
        }
        return cost;
    }
};