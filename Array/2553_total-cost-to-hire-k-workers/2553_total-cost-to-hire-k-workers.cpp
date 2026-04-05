/*
 * Problem  : 2553. Total Cost to Hire K Workers
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Heap (Priority Queue), Simulation
 * URL      : https://leetcode.com/problems/total-cost-to-hire-k-workers/
 */

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> head_workers;
        long long cost = 0;
        int i = 0, j = n - 1;
        for (; i < candidates && i<=j; i++) {
            head_workers.push(costs[i]);
        }
        priority_queue<int, vector<int>, greater<int>> tail_workers;
        for (; j >= n - candidates && j>=i; j--) {
            tail_workers.push(costs[j]);
        }
        int next_head = candidates;
        int next_tail = n - candidates - 1;

        while (k--) {
            if (!tail_workers.size() ||
                (!head_workers.empty() &&
                    head_workers.top() <= tail_workers.top())) {

                cost += head_workers.top();
                head_workers.pop();
                if (next_head <= next_tail) {
                    head_workers.push(costs[next_head]);
                    next_head++;
                }
            } else {
                cost += tail_workers.top();
                tail_workers.pop();
                if (next_head <= next_tail) {
                    tail_workers.push(costs[next_tail]);
                    next_tail--;
                }
            }
        }
        return cost;
    }
};