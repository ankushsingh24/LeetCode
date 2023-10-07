class Solution {
public:
    
    vector<int> dp;
    
    int f(int num)
    {
        if(num <= 3)
            return num;
        
        if(dp[num] != 0)
            return dp[num];
        
        int ans = num;
        for(int i=2 ; i<num ; i++)
        {
            ans = max(ans, i * f(num - i));
        }
        
        return dp[num] = ans;
    }
    
    int integerBreak(int n) 
    {
        if(n <= 3)
        {
            return n-1;
        }
        
        dp = vector(n+1, 0);
        
        return f(n);
    }
};