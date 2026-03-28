/*
 * Problem  : 2392. Successful Pairs of Spells and Potions
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Binary Search, Sorting
 * URL      : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

        int n=spells.size();
        int m=potions.size();
        vector<int> ans;
        int k=0;
        
        int low=0;
        int high=m-1;
        int count;
        while(k<n){
            count=0;
            while(low<=high){
                int mid=(low+high)/2;
                // cout<<spells[k]*potions[mid]<<" ";
                long long product=(long long)spells[k]*(long long)potions[mid];
                if(product>=success){
                    high=mid-1;
                    count=m-mid;
                }else{
                    low=mid+1;
                }
            }
            low=0;
            high=m-1;
            k++;
            ans.push_back(count);
            cout<<"\n";
        }
        
        return ans;
    }
};