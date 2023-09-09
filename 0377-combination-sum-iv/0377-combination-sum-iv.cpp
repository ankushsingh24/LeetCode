class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        
        for(int curTarget=1; curTarget<=target ; curTarget++)
        {
            for(int j=0 ; j<nums.size() ; j++)
            {
                if(curTarget >= nums[j])
                    dp[curTarget] += dp[curTarget - nums[j]];
                else
                    break;
            }
        }
        
        return dp[target];
    }
};