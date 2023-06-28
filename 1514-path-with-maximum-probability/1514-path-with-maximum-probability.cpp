class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<double> maxProb(n);
        maxProb[start] = 1.0;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            bool hasUpdate = false;
            for(int j=0 ; j<edges.size() ; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                double pathProb = succProb[j];
                
                if(maxProb[v] < pathProb * maxProb[u])
                {
                    maxProb[v] = pathProb * maxProb[u];
                    hasUpdate = true;
                }
                
                if(maxProb[u] < pathProb * maxProb[v])
                {
                    maxProb[u] = pathProb * maxProb[v];
                    hasUpdate = true;
                }
            }
            
            if(!hasUpdate)
                break;
        }
        
        return maxProb[end];
    }
};