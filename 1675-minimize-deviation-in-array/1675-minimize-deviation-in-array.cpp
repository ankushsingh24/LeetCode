class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        int min_n = INT_MAX, ans = INT_MAX, x;
        priority_queue<int> pq;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            nums[i] = nums[i] % 2 ? nums[i]*2 : nums[i];
            pq.push(nums[i]);
            min_n = min(min_n, nums[i]);
        }
        
        while(pq.top() % 2 == 0)
        {
            ans = min(ans, pq.top() - min_n);
            min_n = min(min_n, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        x = pq.top() - min_n;
        
        return min(ans, x);
    }
};