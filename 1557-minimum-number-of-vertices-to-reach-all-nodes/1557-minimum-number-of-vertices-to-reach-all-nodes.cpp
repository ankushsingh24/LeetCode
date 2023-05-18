class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<bool> isIncomingEdgeExists(n, false);
        
        for(vector<int> &edge: edges)
            isIncomingEdgeExists[edge[1]] = true;
        
        vector<int> ans;
        for(int i=0 ; i<n ; i++)
        {
            if(!isIncomingEdgeExists[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};