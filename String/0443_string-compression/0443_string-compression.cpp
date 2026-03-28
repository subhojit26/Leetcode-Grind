/*
 * Problem  : 443. String Compression
 * Difficulty: Medium
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/string-compression/
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        int freq=1;
        char ch=chars[0];
        int n=chars.size();
        string st="";
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                freq++;
            }
            else{
                if(freq==1){
                    st+=ch;
                }else{
                    st+=ch;
                    st = st + to_string(freq);
                }
                ch=chars[i];
                freq=1;
            }
        }
        st+=ch;
        if(freq>1){
            st+=to_string(freq);
        }
        
        cout<<st;
        for(int i=0;i<st.length();i++){
            chars[i]=st[i];
        }
        return st.length();
    }
};