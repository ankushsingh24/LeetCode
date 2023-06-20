class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        if(k == 0)
            return nums;
        
        int n = nums.size();
        vector<int> avgs(n, -1);
        
        if(2 * k + 1 > n)
            return avgs;
        
        vector<long long> prefix(n + 1);
        for(int i=0 ; i<n ; i++)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        for(int i=k ; i<(n-k) ; i++)
        {
            int leftBound = i-k, rightBound = i+k;
            long long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int avg = subArraySum / (2 * k + 1);
            avgs[i] = avg;
        }
        
        return avgs;
    }
};