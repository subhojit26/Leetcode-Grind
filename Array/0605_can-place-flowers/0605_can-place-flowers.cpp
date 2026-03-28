/*
 * Problem  : 605. Can Place Flowers
 * Difficulty: Easy
 * Topics   : Array, Greedy
 * URL      : https://leetcode.com/problems/can-place-flowers/
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        int len=flowerbed.size();
        while(i<len && n>0){
            if(flowerbed[i]==0 && flowerbed[max(i-1,0)]==0 && flowerbed[min(i+1,len-1)]==0){
                n--;
                flowerbed[i]=1;
            }
            i++;
        }
        if(n==0){
            return true;
        }
        return false;
    }
};