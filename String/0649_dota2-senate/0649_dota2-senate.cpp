/*
 * Problem  : 649. Dota2 Senate
 * Difficulty: Medium
 * Topics   : String, Greedy, Queue
 * URL      : https://leetcode.com/problems/dota2-senate/
 */

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n=senate.length();

        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }

        while(!r.empty() && !d.empty()){
            int ri=r.front();
            r.pop();
            int di=d.front();
            d.pop();

            if(ri<di){
                r.push(ri+n);
            }else{
                d.push(di+n);
            }
        }
        if(r.empty()){
            return "Dire";
        }else{
            return "Radiant";
        }
    }
};