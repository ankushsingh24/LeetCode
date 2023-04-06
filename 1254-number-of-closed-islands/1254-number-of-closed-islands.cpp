class Solution {
public:
    bool dfs(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if(grid[x][y] == 1 || vis[x][y])
            return true;
        
        vis[x][y] = true;
        bool isClosed = true;       
        vector<int> dirX = {0, 1, 0, -1};
        vector<int> dirY = {-1, 0, 1, 0};
        
        for(int i=0 ; i<4 ; i++)
        {
            int row = x + dirX[i];
            int col = y + dirY[i];
            
            if(!dfs(row, col, n, m, grid, vis))
                isClosed = false;
        }
        
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool> (m));
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] == 0 && !vis[i][j] && dfs(i, j, n, m, grid, vis))
                    cnt++;
            }
        }
        
        return cnt;
    }
};