class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>best_sell(n,-1e9),best_buy(n,-1e9);
        for(int i =0;i<n;i++)best_buy[i] = -prices[i];
        int ans = 0;   
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<i;j++){
                best_sell[i] = max(best_sell[i],best_buy[j] + prices[i]);
            }
            
            for(int j=0;j<i-1;j++){
                best_buy[i] = max(best_buy[i],best_sell[j] - prices[i]);
            }
            
            ans = max(ans,best_sell[i]);
        }
        return ans;
    }
};