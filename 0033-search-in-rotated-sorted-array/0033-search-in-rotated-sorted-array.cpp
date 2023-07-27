class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        int left = 0, right = n - 1;
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[n-1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        int ans = binarySearch(nums, target, 0, left-1);
        
        if(ans != -1)
            return ans;
        
        return binarySearch(nums, target, left, n-1);
        
    }
};