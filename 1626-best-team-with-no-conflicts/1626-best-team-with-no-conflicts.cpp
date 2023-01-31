class Solution {
public:
    int findMax(vector<pair<int, int>> &ageScorePair)
    {
        int n = ageScorePair.size();
        int ans = 0;
        
        vector<int> dp(n);
        for(int i=0 ; i<n ; i++)
        {
            dp[i] = ageScorePair[i].second;
            ans = max(ans, dp[i]);
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i-1 ; j>=0 ; j--)
            {
                if(ageScorePair[i].second >= ageScorePair[j].second)
                    dp[i] = max(dp[i], ageScorePair[i].second + dp[j]);
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
        
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int, int>> ageScorePair;
        for(int i=0 ; i<scores.size() ; i++)
        {
            ageScorePair.push_back({ages[i], scores[i]});
        }
        
        sort(ageScorePair.begin(), ageScorePair.end());
        
        return findMax(ageScorePair);
    }
};