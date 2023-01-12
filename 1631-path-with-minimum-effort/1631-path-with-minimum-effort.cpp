class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        
        // {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row == n-1 && col == m-1)
                return diff;
            
            for(int i=0 ; i<4 ; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >= 0 && newr < n && newc >=0 && newc < m)
                {
                    int newEffort = max(diff, abs(heights[row][col] - heights[newr][newc]));
                    if(newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};