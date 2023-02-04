class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        for(int i=0 ; i<s1.size() ; i++)
            v1[s1[i] - 'a']++;
        
        int i=0, j=0;
        
        while(j < s2.size())
        {
            v2[s2[j] - 'a']++;
            
            if(j - i + 1 == s1.size())
                if(v1 == v2)
                    return true;
            
            if(j - i + 1 < s1.size())
                j++;
            
            else
            {
                v2[s2[i] - 'a']--;
                i++; 
                j++;
            }
        }
        
        return false;
    }
};