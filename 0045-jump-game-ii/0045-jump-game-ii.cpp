class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int curReach = 0;
        int curMax = 0;
        int jumps = 0;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            curMax = max(curMax, i + nums[i]);
           
            if(i == curReach)
            {
                jumps++;
                curReach = curMax;
            }
        }
        return jumps;
    }
};