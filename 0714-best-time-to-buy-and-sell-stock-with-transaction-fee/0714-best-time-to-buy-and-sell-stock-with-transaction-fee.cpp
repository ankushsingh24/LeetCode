class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, int n, int fees, vector<vector<int>> &dp)
    {
        if(idx == n)
            return 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        if(buy)
            return dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, prices, n, fees, dp), 
                                      0 + f(idx+1, 1, prices, n, fees, dp));
        else
            return dp[idx][buy] = max((prices[idx] - fees) + f(idx+1, 1, prices, n, fees, dp), 
                                      0 + f(idx+1, 0, prices, n, fees, dp));
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, n, fee, dp);
    }
};