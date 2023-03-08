class Solution {
public:
    bool check(vector<int>& piles, int mid, int h)
    {
        long n = piles.size(), total = 0;
        for(int i=0 ; i<n ; i++)
        {
            total += (piles[i] / mid);
            if(piles[i] % mid != 0)
                total++;
        }
        
        return total > h;
    }
        
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size();
        
        int left = 1, right = 1000000000;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(check(piles, mid, h))
                left = mid + 1;
            else 
                right = mid - 1;
        }
        
        return left;
    }
};