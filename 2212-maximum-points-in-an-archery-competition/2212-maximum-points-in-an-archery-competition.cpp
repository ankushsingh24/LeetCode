class Solution {
public:
    vector<int> ans;
    int target = 0;
    
    void rec(int n, int numArrows, vector<int> &aliceArrows, int sum, vector<int> res)
    {
        if(n == -1 || numArrows <= 0)
        {
            if(sum > target)
            {
                target = sum;
                if(numArrows > 0)
                    res[0] += numArrows;
                ans = res;
            }
            
            return;
        }
        
        int req = aliceArrows[n] + 1;
        if(req <= numArrows)
        {
            res[n] = req;
            rec(n-1, numArrows-req, aliceArrows, sum+n, res);
            res[n] = 0;
        }
        
        rec(n-1, numArrows, aliceArrows, sum, res);
        return;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) 
    {
        vector<int> res(12, 0);
        rec(11, numArrows, aliceArrows, 0, res);
        return ans;
    }
};