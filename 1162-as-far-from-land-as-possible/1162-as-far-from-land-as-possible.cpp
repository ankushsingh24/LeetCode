class Solution {
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
public:
    bool isPos(int r, int c, int n)
    {
        return (r >=0 && c >= 0 && r < n && c < n);
    }
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, -1));
        queue<vector<int>> q;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int ans = 0;
        while(!q.empty())
        {
            vector<int> it = q.front();
            q.pop();
            
            int r = it[0];
            int c = it[1];
            
            if(grid[r][c] == 0)
                ans = max(ans, dist[r][c]);
            
            for(int i=0 ; i<4 ; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(isPos(nr, nc, n) && dist[nr][nc] == -1)
                {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                }
            }
        }
        
        return (ans == 0) ? -1 : ans;
    }
};