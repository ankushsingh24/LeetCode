class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        queue<int> q;
        
        for(int i=0 ; i<n ; i++)
        {
            if(color[i]) // skip already colored nodes
                continue;
            
            color[i] = 1; // color seed i to be A (doesn't matter A or B) 
            q.push(i);
            
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                
                for(int neighbor: graph[cur])
                {
                    if(!color[neighbor])
                    {
                        color[neighbor] = -color[cur]; // if uncolored, color with opposite color
                        q.push(neighbor);
                    }
                    else if(color[neighbor] == color[cur])
                        return false; // if already colored with same color, can't be bipartite!
                }
            }
        }
        
        return true;
    }
};