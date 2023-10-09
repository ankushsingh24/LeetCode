class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(2, -1);
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
            {
                ans[0] = mid;
                right = mid - 1;
            }
            
            else
                nums[mid] < target ? (left = mid + 1) : (right = mid - 1);
        }
        
        left = 0;
        right = nums.size() - 1;
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
            {
                ans[1] = mid;
                left = mid + 1;
            }
            
            else
                nums[mid] < target ? (left = mid + 1) : (right = mid - 1);
        }
        
        return ans;
    }
};