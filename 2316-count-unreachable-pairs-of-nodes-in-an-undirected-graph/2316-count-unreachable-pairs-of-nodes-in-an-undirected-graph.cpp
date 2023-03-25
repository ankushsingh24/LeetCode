class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &mp, long long &cnt, vector<int> &vis)
    {
        vis[node] = 1;
        cnt++;
        for(auto &i: mp[node])
        {
            if(vis[i] == 0)
                dfs(i, mp, cnt, vis);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> mp;
        int m = edges.size();
        
        for(int i=0 ; i<m ; i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long ans = ((long long)n*(n-1))/2;
        
        vector<int> vis(n, 0);
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                long long cnt = 0;
                dfs(i ,mp, cnt, vis);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        
        return ans;
    }
};