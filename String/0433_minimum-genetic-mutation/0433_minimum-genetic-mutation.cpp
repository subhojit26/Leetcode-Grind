/*
 * Problem  : 433. Minimum Genetic Mutation
 * Difficulty: Medium
 * Topics   : Hash Table, String, Breadth-First Search
 * URL      : https://leetcode.com/problems/minimum-genetic-mutation/
 */

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int steps=0;
        set<string> st(bank.begin(),bank.end());
        queue<string> q;
        q.push(startGene);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string cur=q.front();
                q.pop();
                if(cur==endGene){
                    return steps;
                }
                st.erase(cur);
        
                for(int i=0;i<8;i++){
                    string t=cur;
                    t[i]='A';
                    if(st.count(t)) q.push(t);
                    t[i]='C';
                    if(st.count(t)) q.push(t);
                    t[i]='G';
                    if(st.count(t)) q.push(t);
                    t[i]='T';
                    if(st.count(t)) q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};