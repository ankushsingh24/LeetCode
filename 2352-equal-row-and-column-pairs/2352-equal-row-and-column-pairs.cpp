class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        map<vector<int>, int> mp;
        
        for(int i=0 ; i<n ; i++)
        {
            mp[grid[i]]++;
        }
        
        for(int i=0 ; i<m ; i++)
        {
            vector<int> v;
            for(int j=0 ; j<n ; j++)
            {
                v.push_back(grid[j][i]);
            }
            
            ans += mp[v];
        }
        
        return ans;
    }
};