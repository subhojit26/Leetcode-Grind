/*
 * Problem  : 937. Online Stock Span
 * Difficulty: Medium
 * Topics   : Stack, Design, Monotonic Stack, Data Stream
 * URL      : https://leetcode.com/problems/online-stock-span/
 */

class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) { 
      int ans=1;
       while(!st.empty() && price>=st.top().first){
          ans+=st.top().second;
          st.pop();
        }
     st.push({price,ans});
    return ans; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */