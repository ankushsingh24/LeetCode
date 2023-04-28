class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        for(int neighbor: adj[node])
        {
            if(!vis[neighbor])
                dfs(neighbor, adj, vis);
        }
    }
    
    bool isSimilar(string &a, string &b)
    {
        int diff = 0;
        for(int i=0 ; i<a.size() ; i++)
        {
            if(a[i] != b[i])
                diff++;
        }
        
        return diff == 0 || diff == 2;
    }
    
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n);
        int cnt = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};