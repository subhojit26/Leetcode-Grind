/*
 * Problem  : 151. Reverse Words in a String
 * Difficulty: Medium
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.length();
        vector<string> v;
        string temp="";
        string ans="";
        while(i<n){
            if(s[i]==' '){
                if(temp==""){
                    i++;
                }
                else{
                    v.push_back(temp);
                    temp="";
                    i++;
                }
            }
            else{
                while(i<n && s[i]!=' '){
                    temp=temp+s[i++];
                }
            }
        }
        v.push_back(temp);
        for(int j=0;j<v.size();j++){
            ans=v[j]+" "+ans;
        }
        if(ans[ans.length()-1]==' ' && ans[0]==' '){
            ans=ans.substr(1);
            ans=ans.substr(0,ans.length()-1);
        }
        else if(ans[ans.length()-1]==' '){
            ans=ans.substr(0,ans.length()-1);
        }
        return ans;
        
    }
};