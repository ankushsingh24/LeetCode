class Solution {
public:
    long long fuel = 0;
    
    long long dfs(int node, int parent, vector<vector<int>> &adj, int &seats)
    {
        int cnt = 1;
        
        for(auto &child: adj[node])
        {
            if(child != parent)
                cnt += dfs(child, node, adj, seats);
        }
        
        if(node != 0)
            fuel += ceil((double)cnt/ seats);
        
        return cnt;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n = roads.size();
        vector<vector<int>> adj(n+1);
       
        for(auto road: roads)
        {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        dfs(0, -1, adj, seats);
        
        return fuel;
    }
};