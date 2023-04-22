class Solution {
public:
    int lcs(string& s1, string& s2, int n, int m, vector<vector<int>>& memo) 
    {
        if(n == 0 || m == 0)
            return 0;
        
        if(memo[n][m] != -1)
            return memo[n][m];
        
        if(s1[n-1] == s2[m-1])
            return memo[n][m] = 1 + lcs(s1, s2, n-1, m-1, memo);
        
        return memo[n][m] = max(lcs(s1, s2, n-1, m, memo), lcs(s1, s2, n, m-1, memo));
    }
    
    int minInsertions(string s) 
    {
        int n = s.size();
        string revS = s;
        reverse(revS.begin(), revS.end());
        vector<vector<int>> memo(n+1, vector<int> (n+1));
        
        for(int i=0 ; i<=n ; i++)
            for(int j=0 ; j<=n ; j++)
                memo[i][j] = -1;
        
        return n - lcs(s, revS, n, n, memo);
    }
};