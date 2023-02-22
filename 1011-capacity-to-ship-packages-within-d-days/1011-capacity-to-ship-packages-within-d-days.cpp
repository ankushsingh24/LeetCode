class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 0, right = 0;
        for(auto w: weights)
        {
            left = max(left, w);
            right += w;
        }
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            int need = 1, cur = 0;
            
            for(int i=0 ; i<weights.size() && need <= days ; cur += weights[i++])
            {
                if(cur + weights[i] > mid)
                {
                    need++;
                    cur = 0;
                }
            }
            
            if(need > days)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};