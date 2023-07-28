class Solution {
public:
    int maxDiff(vector<int> &nums, int left, int right, int n, vector<vector<int>> &dp)
    {
        if(dp[left][right] != -1)
            return dp[left][right];
        
        if(left == right)
            return nums[left];
        
        int scoreByLeft = nums[left] - maxDiff(nums, left+1, right, n, dp);
        int scoreByRight = nums[right] - maxDiff(nums, left, right-1, n, dp);
        
        return dp[left][right] = max(scoreByLeft, scoreByRight);
    }
    
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return maxDiff(nums, 0, n-1, n, dp) >= 0;
    }
};