class Solution {
public:
    int ans = -1;
    
    void dfs(int node, vector<int> &edges, unordered_map<int, int> &dist, vector<bool> &vis)
    {
        vis[node] = true;
        int neighbor = edges[node];
        
        if(neighbor != -1 && !vis[neighbor])
        {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, vis);
        }
        
        else if(neighbor != -1 && dist.count(neighbor))
        {
            ans = max(ans, dist[node] - dist[neighbor] + 1);
        }
    }
    
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size();
        vector<bool> vis(n);
        
        for(int i=0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, vis);
            }
        }
        
        return ans;
    }
};