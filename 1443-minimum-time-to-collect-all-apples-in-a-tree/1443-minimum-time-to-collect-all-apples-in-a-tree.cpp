class Solution {
public:
    int dfs(int node, int dist, int prev, vector<vector<int>> &adj, vector<bool> &hasApple)
    {
        int result = 0, temp;
        for(auto &i: adj[node])
        {
            if(i != prev)
            {
                temp = dfs(i, dist + 1, node, adj, hasApple);
                if(temp)
                {
                    result += temp - dist;
                }
            }
        }
        
        if(result || hasApple[node])
            return result + dist;
        
        return 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> adj(n);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, 0, -1, adj, hasApple) * 2;
    }
};