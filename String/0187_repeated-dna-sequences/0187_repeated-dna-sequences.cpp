/*
 * Problem  : 187. Repeated DNA Sequences
 * Difficulty: Medium
 * Topics   : Hash Table, String, Bit Manipulation, Sliding Window, Rolling Hash, Hash Function
 * URL      : https://leetcode.com/problems/repeated-dna-sequences/
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int i=0;
        int j=0;
        int n=s.length();
        vector<string> ans;
        set<string> st;
        string t="";
        while(j<n){
            t=t+s[j];
            if(j-i+1==10)
            {
                mp[t]++;
                if(mp[t]>1){
                    st.insert(t);
                }
                i++;
                t=s.substr(i,9);
            }
            j++;
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};