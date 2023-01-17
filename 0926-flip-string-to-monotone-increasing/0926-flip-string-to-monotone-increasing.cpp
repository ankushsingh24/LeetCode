class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int zero = 0, one = 0;
        for(char c: s)
        {
            if(c == '0')
                zero++;
            else
                one++;
            
            zero = min(zero, one);
        }
        return zero;
    }
};