class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int zero = 0;
        int ans = 0;
        int start = 0;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0)
                zero++;
            
            while(zero > 1)
            {
                if(nums[start] == 0)
                    zero--;
                start++;
            }
            
            ans = max(ans, i - start);
        }
        
        return ans;
    }
};