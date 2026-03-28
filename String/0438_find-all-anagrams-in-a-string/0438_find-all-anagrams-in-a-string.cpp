/*
 * Problem  : 438. Find All Anagrams in a String
 * Difficulty: Medium
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/find-all-anagrams-in-a-string/
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls=s.length();
        int lp=p.length();
        map<char, int> mp,mp1;
        vector<int>ans;
        for(int i=0;i<lp;i++){
            mp[p[i]]++;
        }
        int start=0;
        int end=0;
        while(end<ls){
            if(mp.find(s[end])!=mp.end()){
                mp1[s[end]]++;

                while(mp1[s[end]]>mp[s[end]]){
                    mp1[s[start]]--;
                    start++;
                }

                if(end-start+1==lp){
                    ans.push_back(start);
                }
            }else{
                mp1.clear();
                start=end+1;
            }
            end++;
        }
        return ans;

    }
};