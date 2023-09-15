class Solution {
public:
    
    int SqSum(int n)
    {
        int sum = 0;
        
        while(n)
        {
            int rem = n % 10;
            sum += rem * rem;
            n = n / 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) 
    {        
        while(1)
        {
            if(n == 89)
                return false;
            if(n == 1)
                return true;
            
            n = SqSum(n);
        }
    }
};