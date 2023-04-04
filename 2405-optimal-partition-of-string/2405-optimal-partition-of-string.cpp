class Solution {
public:
    int partitionString(string s) 
    {
        int n = s.size();
        vector<int> last(26, -1);
        int cnt = 1, substringStart = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(last[s[i] - 'a'] >= substringStart)    
            {
                cnt++;
                substringStart = i;
            }
            
            last[s[i] - 'a'] = i;
        }
        
        return cnt;
    }
};