/*
 * Problem  : 13. Roman to Integer
 * Difficulty: Easy
 * Topics   : Hash Table, Math, String
 * URL      : https://leetcode.com/problems/roman-to-integer/
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int l=s.length();
        int sum=0;
        for(int i=0;i<l;i++){
            if(i<l-1 && mp[s[i]]<mp[s[i+1]]){
                cout<<sum<<" ";
                sum=mp[s[i+1]]-mp[s[i]]+sum;
                i++;
            }else{
                sum+=mp[s[i]];
            }
        }
        return sum;
    }
};