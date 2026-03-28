/*
 * Problem  : 2215. Finding 3-Digit Even Numbers
 * Difficulty: Easy
 * Topics   : Array, Hash Table, Recursion, Sorting, Enumeration
 * URL      : https://leetcode.com/problems/finding-3-digit-even-numbers/
 */

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> even;
        vector<int> odd;
        set<int> ans;
        vector<int> res;

        int n=digits.size();

        for(int i=0;i<n;i++){
            if(digits[i]%2==0){
                even.push_back(digits[i]);
            }else{
                odd.push_back(digits[i]);
            }
        }

        if(even.size()==0){
            return res;
        }

        for(int i=0;i<even.size();i++){
            if(even[i]==0){
                continue;
            }
            for(int j=0;j<odd.size();j++){
                for(int k=0;k<even.size();k++){
                    if(k==i){
                        continue;
                    }
                    int digit=even[i]*100+odd[j]*10+even[k];
                    ans.insert(digit);
                }
            }
        }

        for(int i=0;i<even.size();i++){
            if(even[i]==0){
                continue;
            }
            for(int j=0;j<even.size();j++){
                if(i==j){
                    continue;
                }
                for(int k=0;k<even.size();k++){
                    if(k==i || k==j){
                        continue;
                    }
                    int digit=even[i]*100+even[j]*10+even[k];
                    ans.insert(digit);
                }
            }
        }

        for(int i=0;i<odd.size();i++){
            for(int j=0;j<odd.size();j++){
                if(i==j){
                    continue;
                }
                for(int k=0;k<even.size();k++){
                    int digit=odd[i]*100+odd[j]*10+even[k];
                    ans.insert(digit);
                }
            }
        }

        for(int i=0;i<odd.size();i++){
            for(int j=0;j<even.size();j++){
                for(int k=0;k<even.size();k++){
                    if(k==j){
                        continue;
                    }
                    int digit=odd[i]*100+even[j]*10+even[k];
                    ans.insert(digit);
                }
            }
        }
        while(ans.size()!=0){
            int ele=*(ans.begin());
            ans.erase(ele);
            res.push_back(ele);
        }
        sort(res.begin(),res.end());
        return res;
    }
};