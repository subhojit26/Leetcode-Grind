/*
 * Problem  : 2800. Minimum String Length After Removing Substrings
 * Difficulty: Easy
 * Topics   : String, Stack, Simulation
 * URL      : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
 */

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            
            if(st.size()>0){
                if(s[i]=='B'){
                    if(st.top()=='A'){
                        st.pop();
                        continue;
                    }
                    
                }
                if(s[i]=='D'){
                    if(st.top()=='C'){
                        st.pop();
                        continue;
                    }
                    
                }
            }
            st.push(s[i]);
            
        }
        return st.size();
    }
};