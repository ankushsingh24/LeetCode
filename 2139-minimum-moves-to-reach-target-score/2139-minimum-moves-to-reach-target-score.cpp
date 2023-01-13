class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        if(maxDoubles == 0)
            return target - 1;
        
        int cnt = 0;
        while(target != 1)
        {
            if(maxDoubles == 0)
                return cnt + target - 1;
            
            if(target % 2 == 0)
            {
                target /= 2;
                maxDoubles--;
            }
            
            else if(target % 2 == 1)
                target--;
            
            cnt++;
        }
        
        return cnt;
    }
};