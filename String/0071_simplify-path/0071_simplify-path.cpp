/*
 * Problem  : 71. Simplify Path
 * Difficulty: Medium
 * Topics   : String, Stack
 * URL      : https://leetcode.com/problems/simplify-path/
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int len=path.length();
        int l=0;
        while(l<len){
            if(path[l]=='/'){
                while(l<len && path[l]=='/'){
                    l++;
                }
            }else if(path[l]=='.'){
                string temp="";
                while(l<len && path[l]!='/'){
                    temp=temp+path[l];
                    l++;
                }
                if(temp==".."){
                    if(!st.empty())
                    st.pop();
                }else if(temp=="."){
                    continue;
                }else{
                    st.push(temp);
                }
            }else{
                string temp="";
                while(l<len && path[l]!='/' && path[l]!='.'){
                    temp=temp+path[l];
                    l++;
                }
                st.push(temp);
            }
            
        }
        string ans="";
        while(!st.empty()){
            string t=st.top();
            ans="/"+t+ans;
            st.pop();
        }
        return ans==""?"/":ans;
    }
};