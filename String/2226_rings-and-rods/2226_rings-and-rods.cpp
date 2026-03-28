/*
 * Problem  : 2226. Rings and Rods
 * Difficulty: Easy
 * Topics   : Hash Table, String
 * URL      : https://leetcode.com/problems/rings-and-rods/
 */

class Solution {
public:
    int countPoints(string rings) {
        int len=rings.length();
        int ans=0;
        unordered_map<char, set<char>> mp;
        for(int i=0;i<len;i++){
            char key=rings[i];
            if(rings[i]>='0' && rings[i]<='9' && mp[key].size()!=3){
                char key=rings[i];
                char val=rings[i-1];
                mp[key].insert(val);
                if(mp[key].size()==3){
                    ans++;
                }
            }
        }
        return ans;
    }
};