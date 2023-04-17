class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int n = candies.size();
        vector<bool> res(n, true);
        
        int maxi = *max_element(candies.begin(), candies.end());
        
        for(int i=0 ; i<n ; i++)
        {
            candies[i] = candies[i] - maxi + extraCandies;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            if(candies[i] < 0)
                res[i] = false;
        }
        
        return res;
    }
};