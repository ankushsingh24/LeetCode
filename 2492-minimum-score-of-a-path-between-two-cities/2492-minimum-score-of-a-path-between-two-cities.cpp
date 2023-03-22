class Solution {
public:
    int bfs(int n, vector<vector<pair<int, int>>> adj)
    {
        vector<bool> visit(n+1);
        queue<int> q;
        int ans = INT_MAX;
        
        q.push(1);
        visit[1] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &edge: adj[node])
            {
                ans = min(ans, edge.second);
                if(!visit[edge.first])
                {
                    visit[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return ans;
    }
    
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto &road: roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        return bfs(n, adj);
    }
};