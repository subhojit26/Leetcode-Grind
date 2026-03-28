/*
 * Problem  : 3235. Minimum Cost to Convert String I
 * Difficulty: Medium
 * Topics   : Array, String, Graph Theory, Shortest Path
 * URL      : https://leetcode.com/problems/minimum-cost-to-convert-string-i/
 */

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        long long ans=0;
        vector<vector<int>> v(n+1,vector<int> (n+1,INT_MAX));
        for(int i=0;i<n;i++){
            v[i][i]=0;
        }

        for(int i=0;i<changed.size();i++){
            v[original[i]-'a'][changed[i]-'a']=min(v[original[i]-'a'][changed[i]-'a'],cost[i]);
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(v[i][via]!=INT_MAX && v[via][j]!=INT_MAX){
                        v[i][j]=min(v[i][j],v[i][via]+v[via][j]);
                    }
                }
            }
        }
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int cost=v[source[i]-'a'][target[i]-'a'];
                if(cost==INT_MAX) return -1;
                ans+=cost;
            }
            
        }
        return ans;
    }
};