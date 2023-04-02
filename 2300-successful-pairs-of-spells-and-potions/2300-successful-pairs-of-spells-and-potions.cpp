class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n = spells.size();
        int m = potions.size();
        
        vector<int> pairs(n, 0);
        
        sort(potions.begin(), potions.end());
        
        for(int i=0 ; i<n ; i++)
        {
            int low = 0, high = m;
            
            while(low < high)
            {
                int mid = low + (high - low) / 2;                    
                
                if((long)spells[i] * (long)potions[mid] >= success)
                    high = mid;
                else
                    low = mid + 1;
            }
            
            pairs[i] = m - low;
        }
        
        return pairs;
    }
};