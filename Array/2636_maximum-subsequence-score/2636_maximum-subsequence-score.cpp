/*
 * Problem  : 2636. Maximum Subsequence Score
 * Difficulty: Medium
 * Topics   : Array, Greedy, Sorting, Heap (Priority Queue)
 * URL      : https://leetcode.com/problems/maximum-subsequence-score/
 */

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            minHeap.push(v[i].second);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                ans = max(ans, sum * v[i].first);
            }
        }
        return ans;
    }
};