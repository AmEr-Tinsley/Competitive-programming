class Solution {
public:
    /*
        best_sell(x) : greatest profit could be made selling at price x on the i'th day.
        best_buy(x) : greatest profit made when buying at price x on the i'th day.
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),ans = 0;
        const int N = 10001;
        vector<int>best_sell(N,-1e9),best_buy(N,-1e9);
        for(int i = 0;i<n;i++){
            int p = prices[i];
            for(int j = 0;j<p;j++){
                best_sell[p] = max(best_sell[p],best_buy[j] + p);
            }
            best_buy[p] = max(best_buy[p],ans - p);
            ans = max(ans,best_sell[p]);
        }
        return ans;
    }
};