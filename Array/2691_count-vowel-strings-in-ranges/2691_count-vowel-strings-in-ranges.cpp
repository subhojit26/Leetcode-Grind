/*
 * Problem  : 2691. Count Vowel Strings in Ranges
 * Difficulty: Medium
 * Topics   : Array, String, Prefix Sum
 * URL      : https://leetcode.com/problems/count-vowel-strings-in-ranges/
 */

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix;
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            int l=str.length();
            if((str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u') && (str[l-1]=='a' || str[l-1]=='e' || str[l-1]=='i' || str[l-1]=='o' || str[l-1]=='u')){
                prefix.push_back(1);
            }else{
                prefix.push_back(0);
            }
        }
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i]+prefix[i-1];
        }
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int u=queries[i][1];

            if(l>0){
                ans.push_back(prefix[u]-prefix[l-1]);
            }else{
                ans.push_back(prefix[u]);
            }
        }
        return ans;
    }
};