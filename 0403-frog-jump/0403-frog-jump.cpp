class Solution {
public:
    
    unordered_map<int, int> mark;
    int dp[2001][2001];
    
    int solve(vector<int> &stones, int n, int idx, int prevJump)
    {
        if(idx == n-1)
            return 1;
        
        if(dp[idx][prevJump] != -1)
            return dp[idx][prevJump];
        
        int ans = false;
        
        for(int nextJump = prevJump - 1 ; nextJump <= prevJump + 1 ; nextJump++)
        {
            if(nextJump > 0 && mark.find(stones[idx] + nextJump) != mark.end())
                ans = ans || solve(stones, n, mark[stones[idx] + nextJump], nextJump);
        }
        
        return dp[idx][prevJump] = ans;
    }
    
    bool canCross(vector<int>& stones) 
    {
        for(int i=0 ; i<stones.size() ; i++)
            mark.insert({stones[i], i});
        
        memset(dp, -1, sizeof(dp));
        
        return solve(stones, stones.size(), 0, 0);
    }
};