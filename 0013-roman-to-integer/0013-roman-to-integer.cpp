class Solution {
public:
    int romanToInt(string s) 
    {
        int n = s.size();
        unordered_map<char, int> map;
        
        map = {
            {'I', 1}, {'V', 5}, 
            {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, 
            {'M', 1000}
        };
        
        int ans = 0;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            if(map[s[i]] < map[s[i+1]])
                ans -= map[s[i]];
            
            else
                ans += map[s[i]];
        }
        
        ans += map[s.back()];
        
        return ans;
    }
};