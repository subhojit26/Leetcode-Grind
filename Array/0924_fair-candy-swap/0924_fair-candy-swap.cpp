/*
 * Problem  : 924. Fair Candy Swap
 * Difficulty: Easy
 * Topics   : Array, Hash Table, Binary Search, Sorting
 * URL      : https://leetcode.com/problems/fair-candy-swap/
 */

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        map<int, int> mp;
        for(int i=0;i<bobSizes.size();i++){
            mp[bobSizes[i]]++;
        }

        int sumA=accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sumB=accumulate(bobSizes.begin(),bobSizes.end(),0);


        bool a=sumA>sumB?true:false;

        if(a){
            int diff=sumA-(sumA+sumB)/2;
            for(int i=0;i<aliceSizes.size();i++){
                if(mp.find(aliceSizes[i]-diff)!=mp.end()){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(aliceSizes[i]-diff);
                    break;
                }
            }
        }else{
            int diff=sumB-(sumA+sumB)/2;
            for(int i=0;i<aliceSizes.size();i++){
                if(mp.find(aliceSizes[i]+diff)!=mp.end()){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(aliceSizes[i]+diff);
                    break;
                }
            }
        }
        return ans;
        
    }
};