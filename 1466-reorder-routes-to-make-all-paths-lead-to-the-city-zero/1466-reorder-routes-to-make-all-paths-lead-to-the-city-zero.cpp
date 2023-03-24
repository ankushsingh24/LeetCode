class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<int> visited(n);
        vector<vector<int>> adj(n), back(n);
        queue<int> q;
        int ans = 0;
        
        q.push(0);
        for(auto c: connections)
        {
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            visited[cur] = 1;
            
            for(auto a: adj[cur])
            {
                if(!visited[a])
                {
                    ans++;
                    q.push(a);
                }
            }
            
            for(auto b: back[cur])
            {
                if(!visited[b])
                    q.push(b);
            }
        }
        
        return ans;
    }
};