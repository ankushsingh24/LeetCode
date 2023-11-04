class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int ans = 0;
        
        for(int i=0 ; i<right.size() ; i++)
        {
            ans = max(ans, n-right[i]);
        }
        
        for(int i=0 ; i<left.size() ; i++)
        {
            ans = max(ans, left[i]);
        }
        
        // Approach 2
        
//         sort(right.begin(), right.end());
//         sort(left.begin(), left.end());
        
//         if(left.size() == 0)
//             return n-right[0];
        
//         if(right.size() == 0)
//             return left[left.size()-1];
        
//         ans = max(n-right[0], left[left.size()-1]);
        
        return ans;
    }
};