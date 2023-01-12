class Solution {
public:
    void dfs(int i, int cnt[], vector<int> &ans, vector<vector<int>> &adj, string &s)
    {
        if(ans[i] == 0)
        {
            ans[i] = 1;
            for(auto j: adj[i])
            {
                int cnt1[26] = {};
                dfs(j, cnt1, ans, adj, s);
                for(int k=0 ; k<26 ; k++)
                    cnt[k] += cnt1[k];
            }
            ans[i] = ++cnt[s[i] - 'a'];
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<vector<int>> adj(n);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int cnt[26] = {};
        
        vector<int> ans(n);
        dfs(0, cnt, ans, adj, labels);
        
        return ans;
    }
};