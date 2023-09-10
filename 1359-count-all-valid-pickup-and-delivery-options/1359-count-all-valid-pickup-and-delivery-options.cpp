class Solution {
    // (2N)! / 2^N
public:
    int countOrders(int n) 
    {
        long ans = 1;
        int MOD =  1e9 + 7;
        
        for(int i=1 ; i <= 2*n ; i++)
        {
            ans = ans * i;   //for (2N)!
            
            if(i%2 == 0)
                ans /= 2;    // dividing when ans is even to prevent decimal
            
            ans %= MOD;
        }
        
        return ans;
    }
};