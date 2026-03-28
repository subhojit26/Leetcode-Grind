/*
 * Problem  : 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Topics   : String, Dynamic Programming, Stack
 * URL      : https://leetcode.com/problems/longest-valid-parentheses/
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        int l=s.length();
        vector<int> arr(l,0);

        for(int i=0;i<l;i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else{
                if(st.empty()){
                    continue;
                }else if(s[i]==')' && st.top().first=='('){
                    arr[i]=1;
                    arr[st.top().second]=1;
                    st.pop();
                }
            }
        }
        int ans=0;
        int temp=0;
        for(int i=0;i<l;i++){
            if(arr[i]==1){
                temp++;
                ans=max(temp,ans);
            }else{
                temp=0;
            }
        }
        return ans;
    }
};