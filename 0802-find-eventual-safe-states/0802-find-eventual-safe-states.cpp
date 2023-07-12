class Solution {
public:
    // colors: WHITE 0, GRAY 1, BLACK 2;
    bool dfs(int node, vector<int> &color, vector<vector<int>>& graph)
    {
        color[node] = 1;// Initially assume that the node is unsafe.
        
        for(auto cur: graph[node])
        {
            if((color[cur] == 0 && dfs(cur, color, graph)) || color[cur] == 1)
                return true;
            
        }
        
        color[node] = 2;// If there is no cycle mark node as safe.
        
        return false;
    }
    
    // Unvisited nodes are marked as 0.
    // Visited but unsafe nodes are marked as 1.
    // Visited but safe nodes are marked as 2.
    
    // We need to find only those nodes which are not part of any cycle. So all those nodes which are           visited and marked safe (have no cycle) must be added to the result.
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        vector<int> color(n);
        vector<int> ans;
        
        // If node is visited and safe or unvisited and does not contain cycle then add it to the answer.
        for(int i=0 ; i<n ; i++)
        {
            if(color[i] == 2 || !dfs(i, color, graph))
                ans.push_back(i);
        }
        
        return ans;
    }
};