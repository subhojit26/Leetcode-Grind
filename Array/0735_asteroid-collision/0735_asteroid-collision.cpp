/*
 * Problem  : 735. Asteroid Collision
 * Difficulty: Medium
 * Topics   : Array, Stack, Simulation
 * URL      : https://leetcode.com/problems/asteroid-collision/
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() && abs(asteroids[i])>st.top()){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(asteroids[i]);
                }
                else if(abs(asteroids[i])==st.top()){
                    st.pop();
                }
            }
        }
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto it:temp){
            ans.push_back(it);
        }
        return ans;
    }
};