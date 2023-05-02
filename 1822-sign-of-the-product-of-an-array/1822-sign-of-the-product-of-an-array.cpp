class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int mul = 1;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] > 0)
                nums[i] = 1;
            else if(nums[i] < 0)
                nums[i] = -1;
            else
                nums[i] = 0;
            
            mul *= nums[i];
        }
        
        if(mul > 0)
            return 1;
        else if(mul < 0)
            return -1;
        else
            return 0;
    }
};