class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<long long> v(forget, 0);
        v[0] = 1;
        
        long long i, j, newPeople;
        
        for(int i=2 ; i<=n ; i++)
        {
            newPeople = 0;
            for(int j=forget-1 ; j>0 ; j--)
            {
                v[j] = v[j-1];
                if(j >= delay)
                    newPeople = (newPeople + v[j])%1000000007;
            }
            v[0] = newPeople;
        }
        
        long long totalPeople = 0;
        for(auto it: v)
            totalPeople += it;
        
        return totalPeople%1000000007;
    }
};