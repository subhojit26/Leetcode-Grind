/*
 * Problem  : 2117. Find Original Array From Doubled Array
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Greedy, Sorting
 * URL      : https://leetcode.com/problems/find-original-array-from-doubled-array/
 */

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        vector<int> ans;
        sort(changed.begin(),changed.end());
        int l=changed.size();
        if(l%2!=0){
            return {};
        }
        for(int i=0;i<l;i++){
            mp[changed[i]]++;
        }

        for(int i=0;i<l;i++){
            if(mp[changed[i]]==0){
                continue;
            }
            if(mp[changed[i]*2]==0){
                return {};
            }
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};