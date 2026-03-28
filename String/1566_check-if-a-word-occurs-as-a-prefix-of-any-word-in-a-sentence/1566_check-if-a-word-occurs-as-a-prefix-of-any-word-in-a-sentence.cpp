/*
 * Problem  : 1566. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * Difficulty: Easy
 * Topics   : Two Pointers, String, String Matching
 * URL      : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 */

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int r=1;
        int l=sentence.length();
        int s=searchWord.length();
        for(int i=0;i<l;i++){
            if(sentence[i]==searchWord[0]){
                int t=i;
                int k=0;
                while(k<s){
                    if(sentence[i+k]==searchWord[k]){
                        k++;
                    }
                    else{
                        break;
                    }
                    if(k==s && (t==0 || sentence[t-1]==' ')){
                        return r;
                    }
                }
            }
            else if(sentence[i]==' '){
                r++;
            }
        }
        return -1;
    }
};