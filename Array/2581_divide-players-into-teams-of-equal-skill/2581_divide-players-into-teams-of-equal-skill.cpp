/*
 * Problem  : 2581. Divide Players Into Teams of Equal Skill
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Two Pointers, Sorting
 * URL      : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
 */

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        long long int sum=skill[i++]+skill[j--];
        long long int p=skill[0]*skill[skill.size()-1];
        while(i<j){
            if(skill[i]+skill[j]==sum){
                p+=skill[i]*skill[j];
                i++;
                j--;
            }
            else{
                return -1;
            }
        }
        return p;

    }
};