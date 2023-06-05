class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n = coordinates.size();
        
        for(int i=2 ; i<n ; i++)
        {
            int dy1 = coordinates[i-1][1] - coordinates[i-2][1];
            int dx1 = coordinates[i-1][0] - coordinates[i-2][0];
            int dy2 = coordinates[i][1] - coordinates[i-1][1];
            int dx2 = coordinates[i][0] - coordinates[i-1][0];
            
            if(dy1 * dx2 != dy2 * dx1)
                return false;
        }
        
        return true;
    }
};