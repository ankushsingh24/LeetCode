class Solution {
public:
    double rec(double x, long long n)
    {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 1.0 / rec(x, -1*n);
        
        if(n%2 == 1)
            return x * rec(x*x, (n-1)/2);
        
        else
            return rec(x*x, n/2);
    }
    
    double myPow(double x, int n) 
    {
        return rec(x, n);    
    }
};