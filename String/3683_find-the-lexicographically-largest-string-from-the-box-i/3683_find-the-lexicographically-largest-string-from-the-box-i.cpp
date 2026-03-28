/*
 * Problem  : 3683. Find the Lexicographically Largest String From the Box I
 * Difficulty: Medium
 * Topics   : Two Pointers, String, Enumeration
 * URL      : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
 */

class Solution {
public:
    string answerString(string s, int k) {
        int n=s.size();
        if (k==1) 
            return s;
        string res="";
        
        char maxChar=*max_element(s.begin(),s.end());
        
        for (int i=0;i<n;i++){
            if (s[i]==maxChar){
                if (min(n-i,n-k+1)<=0) 
                    continue;
                if (s.substr(i,min(n-i,n-k+1))>res){
                    res=s.substr(i,min(n-i,n-k+1));
                }
            }
        }      
        return res;
    }
};
