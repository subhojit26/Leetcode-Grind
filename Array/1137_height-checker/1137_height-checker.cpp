/*
 * Problem  : 1137. Height Checker
 * Difficulty: Easy
 * Topics   : Array, Sorting, Counting Sort
 * URL      : https://leetcode.com/problems/height-checker/
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int freq[101]={0};
        for(int i=0;i<heights.size();i++){
            freq[heights[i]]++;
        }
        int res=0;
        int ptr=1;
        for(int i=0;i<heights.size();i++){
            while(freq[ptr]==0){
                ptr++;
            }
            if(ptr!=heights[i]){
                res++;
            }
            freq[ptr]--;
        }
        return res;

    }
};