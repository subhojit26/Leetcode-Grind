/*
 * Problem  : 30. Substring with Concatenation of All Words
 * Difficulty: Hard
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wl=words[0].length();
        int n=words.size();
        int sl=s.length();
        int totLen=wl*n;
        vector<int> ans;
        map<string, int> wc;
        for(int i=0;i<n;i++){
            wc[words[i]]++;
        }
        for(int i=0;i<wl;i++){
            int start=i;
            int end=i;
            map<string, int> seen;
            while(end+wl<=sl){
                string t=s.substr(end,wl);
                end+=wl;

                if(wc.find(t)!=wc.end()){
                    seen[t]++;
                    while(seen[t]>wc[t]){
                        string remove=s.substr(start,wl);
                        seen[remove]--;
                        start+=wl;
                    }
                    if(end-start==totLen){
                        ans.push_back(start);
                    }
                }else{
                    seen.clear();
                    start=end;
                }
            }
        }
        return ans;
    }
};