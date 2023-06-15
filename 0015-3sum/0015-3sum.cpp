class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return {};
        if(nums[0] > 0)
            return {};
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] > 0)
                break;
            
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int low = i+1, high = n-1;
            int sum = 0;
            
            while(low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                
                if(sum > 0)
                    high--;
                else if(sum < 0)
                    low++;
                else
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int last_low = nums[low], last_high = nums[high];
                    while(low < high && nums[low] == last_low)
                        low++;
                    while(low < high && nums[high] == last_high)
                        high--;
                    
                }
            }
        }
        
        return ans;
    }
};