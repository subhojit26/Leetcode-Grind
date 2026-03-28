/*
 * Problem  : 2650. Split With Minimum Sum
 * Difficulty: Easy
 * Topics   : Math, Greedy, Sorting
 * URL      : https://leetcode.com/problems/split-with-minimum-sum/
 */

class Solution {
public:
    int splitNum(int num)
    {
        string s=to_string(num);
        sort(s.begin(),s.end());
        string a="",b="";
        for(int i=0;i<s.length();i+=2)
        {
            a+=s[i];
        }
        for(int i=1;i<s.length();i+=2)
        {
            b+=s[i];
        }
        int aa=stoi(a);
        int bb=stoi(b);
        return aa+bb;
    }
};