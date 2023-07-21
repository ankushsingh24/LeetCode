class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> lis(n, 1); // stores length of longest sequence till i-th position
        vector<int> count(n, 1); // stores count of longest sequence of length lis[i]
        
        int maxLen = 1;
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(lis[i] < lis[j] + 1) // strictly increasing
                    {
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    
                    else if(lis[i] == 1 + lis[j]) // this means there are more subsequences of same 
                                                  //  length ending at length lis[i]
                    {
                        count[i] += count[j];
                    }
                }
            }
            
            maxLen = max(maxLen, lis[i]);
        }
        
        int numOfLIS = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(lis[i] == maxLen)
                numOfLIS += count[i];
        }
        
        return numOfLIS;
    }
};