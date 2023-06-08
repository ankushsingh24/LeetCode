class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int cnt = 0;
        int n = grid[0].size();
        
        for(auto &row: grid) // Using binary search find the index of the first negative element.
        {
            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin(); // 'index' points to the first negative element
            
            cnt += (n - index);
        }
        
        return cnt;
    }
};