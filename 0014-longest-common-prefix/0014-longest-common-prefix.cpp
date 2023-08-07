class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(), strs.end());
        
        int n = strs.size();
        
        string first = strs[0];
        string last = strs[n-1];
        
        int s = 0;
        
        for(int i=0 ; i<first.size() ; i++)
        {
            if(first[i] == last[i])
                s++;
            else
                break;
        }
        
        return s == 0 ? "" : first.substr(0, s);
    }
};