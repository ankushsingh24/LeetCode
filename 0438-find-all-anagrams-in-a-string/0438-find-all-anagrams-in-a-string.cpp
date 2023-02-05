class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(s.size() < p.size())
            return {};
        
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        vector<int> ans;
        
        for(int i=0 ; i<p.size() ; i++)
            v1[p[i] - 'a']++;
        
        int i=0, j=0;
        
        while(j < s.size())
        {
            v2[s[j] - 'a']++;
            
            if(j - i + 1 == p.size())
                if(v1 == v2)
                    ans.push_back(i);
            
            if(j - i + 1 < p.size())
                j++;
            
            else
            {
                v2[s[i] - 'a']--;
                i++; 
                j++;
            }
        }
        
        return ans;    
    }
};