class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        
        int left = 0, right = 0, temp = 0;
        int ans = INT_MAX;
        
        for(right = 0 ; right < n ; right++)
        {
            temp += nums[right];
            
            while(temp >= target)
            {
                ans = min(ans, right - left + 1);
                temp -= nums[left];
                left++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};