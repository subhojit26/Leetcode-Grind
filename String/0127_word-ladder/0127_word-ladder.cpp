/*
 * Problem  : 127. Word Ladder
 * Difficulty: Hard
 * Topics   : Hash Table, String, Breadth-First Search
 * URL      : https://leetcode.com/problems/word-ladder/
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder=1;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                string cur=q.front();
                q.pop();
                st.erase(cur);
                if(cur==endWord){
                    return ladder;
                }
                for(int i=0;i<cur.size();i++){
                    string temp=cur;
                    char ch=temp[i];
                    for(int j=0;j<26;j++){
                        temp[i]='a'+j;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};