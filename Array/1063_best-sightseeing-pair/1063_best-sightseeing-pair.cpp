/*
 * Problem  : 1063. Best Sightseeing Pair
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/best-sightseeing-pair/
 */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> leftScore(n,0);
        leftScore[0]=values[0];
        for(int i=1;i<n;i++){
            leftScore[i]=max(leftScore[i-1],values[i]+i);
        }
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            ans=max(ans,leftScore[i-1]+values[i]-i);
        }
        return ans;
    }
};