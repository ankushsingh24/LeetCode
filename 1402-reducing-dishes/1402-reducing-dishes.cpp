class Solution {
public:
    int help(vector<int> &satisfaction, int idx, int time, vector<vector<int>> &dp)
    {
        if(idx == satisfaction.size())
            return 0;
        
        if(dp[idx][time] != -1)
            return dp[idx][time];
        
        int pick = time*satisfaction[idx] + help(satisfaction, idx+1, time+1, dp);
        int notPick = help(satisfaction, idx+1, time, dp);
        
        return dp[idx][time] = max(pick, notPick);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return help(satisfaction, 0, 1, dp);
    }
};