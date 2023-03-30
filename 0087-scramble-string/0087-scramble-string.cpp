class Solution {
public:
    bool helper(unordered_map<string, bool> &isScrablePair, string s1, string s2)
    {
        int n = s1.size();
        bool res = false;
        
        if(n == 0)
            return true;
        else if(n == 1)
            return s1 == s2;
        else
        {
            if(isScrablePair.count(s1+s2))
                return isScrablePair[s1+s2];
            if(s1 == s2)
                res = true;
            else
            {
                for(int i=1 ; i<n && !res ; i++)
                {
                    res = res || (helper(isScrablePair, s1.substr(0, i), s2.substr(0, i)) && 
                                  helper(isScrablePair, s1.substr(i, n-i), s2.substr(i, n-i)));
                    
                    res = res || (helper(isScrablePair, s1.substr(0, i), s2.substr(n-i, i)) &&
                                  helper(isScrablePair, s1.substr(i, n-i), s2.substr(0, n-i)));
                }
            }
            
            return isScrablePair[s1+s2] = res;
        }
    }
    
    bool isScramble(string s1, string s2) 
    {
        unordered_map<string, bool> isScrablePair;
        return helper(isScrablePair, s1, s2);
    }
};