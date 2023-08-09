class Solution {
public:
    int count(vector<int> &nums, int threshold)
    {
        int idx = 0, cnt = 0;
        
        while(idx < nums.size() - 1)
        {
            if(nums[idx + 1] - nums[idx] <= threshold)
            {
                cnt++;
                idx++;
            }
            
            idx++;
        }
        
        return cnt;
    }
    
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(count(nums, mid) >= p)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};