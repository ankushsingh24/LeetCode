class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        
        // for(auto i: arr)
        //     cout<<i<<" ";
        
        for(int i=2 ; i<n ; i++)
        {
            if(abs(arr[i] - arr[i-1]) != abs(d))
            {
                return false;
            }
        }
        
        return true;
    }
};