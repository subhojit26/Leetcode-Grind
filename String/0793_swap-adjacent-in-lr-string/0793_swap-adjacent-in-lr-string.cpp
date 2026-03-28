/*
 * Problem  : 793. Swap Adjacent in LR String
 * Difficulty: Medium
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/swap-adjacent-in-lr-string/
 */

class Solution {
public:
    bool canTransform(string start, string target) {
        int n=start.length();
        int sid=0;
        int tid=0;
        int ls=0,lt=0,rs=0,rt=0;
        for(int i=0;i<n;i++){
            if(start[i]=='L'){
                ls++;
            }
            if(start[i]=='R'){
                rs++;
            }
            if(target[i]=='L'){
                lt++;
            }
            if(target[i]=='R'){
                rt++;
            }
        }
        if(ls!=lt || rs!=rt){
            return false;
        }
        while(sid<n && tid<n){
            while(sid<n && start[sid]=='X') sid++;
            while(tid<n && target[tid]=='X') tid++;

            if(sid==n && tid==n) return true;
            if(sid==n || tid==n) return false;

            if(start[sid]!=target[tid] || (start[sid]=='L' && sid<tid) || (target[tid]=='R' && sid>tid)){
                return false;
            }
            sid++;
            tid++;
        }
        return true;
    }
};