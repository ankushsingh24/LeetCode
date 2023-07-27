class Solution {
public:
    bool isPossible(int computers, vector<int>& batteries, long long time)
    {
        long long totalTime = time * computers;
        
        for(long long bTime: batteries)
            totalTime -= min(time, bTime);
        
        return (totalTime <= 0);
    }
    
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long low = 0, high = 0;
        
        int size = batteries.size();
        
        for(long long bTime : batteries)
            high += bTime;
        
        long long ans = 0;
        
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            
            if(isPossible(n, batteries, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return ans;
    }
};