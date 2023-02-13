class Solution {
public:
    int countOdds(int low, int high) 
    {
        // {even, even}
        if(low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;
        
        // {even, odd}
        else if((low % 2 != 0 && high % 2 == 0) || (low % 2 == 0 && high % 2 != 0))
            return 1 + (high - low - 1) / 2;
        
        // {odd, odd}
        else
            return 2 + (high - low - 2) / 2;
    }
};