/*
 * Problem  : 567. Permutation in String
 * Difficulty: Medium
 * Topics   : Hash Table, Two Pointers, String, Sliding Window
 * URL      : https://leetcode.com/problems/permutation-in-string/
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length();
        int l2=s2.length();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        if(l1>l2){
            return false;
        }

        for(int i=0;i<l1;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        if(mp1==mp2){
            return true;
        }

        int l=0;
        for(int r=l1;r<l2;r++){
            mp2[s2[r]]++;
            mp2[s2[l]]--;
            if(mp2[s2[l]]==0){
                mp2.erase(s2[l]);
            }
            l++;

            if(mp1==mp2){
                return true;
            }
        }
        return false;
    }
};