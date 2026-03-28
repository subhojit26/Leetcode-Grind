/*
 * Problem  : 85. Maximal Rectangle
 * Difficulty: Hard
 * Topics   : Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
 * URL      : https://leetcode.com/problems/maximal-rectangle/
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        if(matrix.empty()||matrix[0].empty()){
            return 0;
        }
        int n=matrix[0].size();
        vector<int> heights(n+1,0);
        for(auto row: matrix){
            for(int i=0;i<n;i++){
                heights[i]=(row[i]=='1')?heights[i]+1:0;
            }
            stack<int> st;
            for(int i=0;i<heights.size();i++){
                while(!st.empty() && heights[i]<heights[st.top()]){
                    int h=heights[st.top()];
                    st.pop();
                    int w=st.empty()?i:i-st.top()-1;
                    maxArea=max(maxArea,h*w);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};