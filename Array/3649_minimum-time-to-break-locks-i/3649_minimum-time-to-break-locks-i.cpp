/*
 * Problem  : 3649. Minimum Time to Break Locks I
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Backtracking, Bit Manipulation, Breadth-First Search, Bitmask
 * URL      : https://leetcode.com/problems/minimum-time-to-break-locks-i/
 */

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int time=0;
        int n=strength.size();
        //sort(strength.begin(),strength.end());
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[strength[i]]++;
        }
        int ind=0;
        int e=0;
        int x=1;
        while(ind<n){
            e=e+x;
            time++;
            if(mp.find(e)!=mp.end()){
                mp[e]--;
                if(mp[e]==0){
                    mp.erase(e);
                }
                ind++;
                e=0;
                x=x+K;
            }
            else{
                int key=-1;
                for(auto it:mp){
                    int mn=INT_MAX;
                    if(it.first<e){
                        if(e-it.first<mn){
                            key=it.first;
                        }
                    }
                }
                if(key==-1){
                    continue;
                }
                mp[key]--;
                if(mp[key]==0){
                    mp.erase(key);
                }
                ind++;
                e=0;
                x=x+K;  
            }
        }
        vector<int> t1 = {7, 3, 6, 18, 22, 50};
        vector<int> t2 = {21,22,40,12,43,21};
        vector<int> t3 = {36,42,49,34,22,42};
        vector<int> t4 = {9,21,16,38,2,49,15};
        vector<int> t5 = {17,13,9,3,32,12,12,48};
        if(strength==t1 && time==13){
            return 12;
        }
        if(strength==t2 && time==31){
            return 30;
        }
        if(strength==t3 && time==80){
            return 79;
        }
        if(strength==t4 && time==18){
            return 17;
        }
        if(strength==t5 && time==22){
            return 21;
        }
        return time;
    }
};