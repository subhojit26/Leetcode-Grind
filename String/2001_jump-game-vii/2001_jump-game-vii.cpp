/*
 * Problem  : 2001. Jump Game VII
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming, Sliding Window, Prefix Sum
 * URL      : https://leetcode.com/problems/jump-game-vii/
 */

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int len=s.length();
        q.push(0);
        int farthest=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int start=max(t+minJump,farthest+1);
            for(int i=start;i<min(t+maxJump+1,len);i++){
                if(s[i]=='0'){
                    q.push(i);
                    if(i==len-1){
                        return true;
                    }
                }
            }
            farthest=t+maxJump;
        }
        return false;
    }
};