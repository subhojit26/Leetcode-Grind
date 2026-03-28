/*
 * Problem  : 135. Candy
 * Difficulty: Hard
 * Topics   : Array, Greedy
 * URL      : https://leetcode.com/problems/candy/
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> lhc(n,1);
        int pt=1;
        while(pt<n){
            if(ratings[pt]>ratings[pt-1]){
                lhc[pt]=lhc[pt-1]+1;
            }
            pt++;
        }
        pt=n-2;
        while(pt>=0){
            if(ratings[pt]>ratings[pt+1] && lhc[pt]<=lhc[pt+1]){
                lhc[pt]=lhc[pt+1]+1;
            }
            pt--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //cout<<lhc[i]<<" ";
            ans+=lhc[i];
        }
        return ans;
    }
};