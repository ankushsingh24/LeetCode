class Solution {
public:
    bool validPartition(vector<int>& nums) 
    {
        int n = nums.size();
        
        int dp[4] = {0, 0, 0, 1};
        
        for(int i=0 ; i<n ; i++)
        {
            dp[i % 4] = 0;
            
            if(i-1 >= 0 && nums[i] == nums[i-1])
                dp[i % 4] |= dp[(i + 2) % 4];
            
            if(i-2 >= 0 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
                dp[i % 4] |= dp[(i+1) % 4];
            
            if(i-2 >= 0 && nums[i] - 1 == nums[i-1] && nums[i-1] == nums[i-2] + 1)
                dp[i % 4] |= dp[(i+1) % 4];
        }
        
        return dp[(n-1) % 4];
    }
};