class Solution {
public:
    
    vector<vector<int>> dp;
    
    int dead_end_sum(string &s, int x)
    {
        int sum = 0;
        
        for( ; x < s.size() ; x++)
            sum += int(s[x]);
        return sum;
    }
    
    int sub(string &s1, string &s2, int i, int j)
    {
        int n = s1.size();
        int m = s2.size();
        int sum = 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == n || j == m)
        {
            if(i == n && j == m)
                return 0; 
            return (i == n) ? dead_end_sum(s2, j) : dead_end_sum(s1, i);
        }
        
        if(s1[i] == s2[j])
            sum = sub(s1, s2, i+1, j+1);
        
        else
            sum = min(sub(s1, s2, i+1, j) + int(s1[i]), sub(s1, s2, i, j+1) + int(s2[j]));    
        
        return dp[i][j] = sum;
    }
    
    int minimumDeleteSum(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();
        
        dp.assign(n+1, vector<int> (m+1, -1));
            
        return sub(s1, s2, 0, 0);
    }
};