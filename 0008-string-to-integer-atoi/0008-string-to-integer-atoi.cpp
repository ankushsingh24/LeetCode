class Solution {
public:
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    
    int myAtoi(string s) 
    {
        int n = s.size();
        
        if(n == 0)
            return 0;
        
        int index = 0;
        while(index < n && s[index] == ' ')
            index++;
        
        if(index == n)
            return 0;
        
        char ch;
        bool isNegative = (ch = s[index]) == '-';
        
        if(isNegative || ch == '+')
            index++;
        
        int maxLimit = INT_MAX / 10;
        int result = 0;
        
        while(index < n && isDigit(ch = s[index]))
        {
            int digit = ch - '0';
            
            if(result > maxLimit || (result == maxLimit && digit > 7))
                return isNegative ? INT_MIN : INT_MAX;
            
            result = (result * 10) + digit;
            
            index++;
        }
        
        return isNegative ? -result : result;
    }
};