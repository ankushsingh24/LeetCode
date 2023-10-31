class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n = pref.size();
        
        vector<int> arr;
        
        arr.push_back(pref[0]);
        for(int i=1 ; i<n ; i++)
        {
            arr.push_back(pref[i-1] ^ pref[i]);
        }
        
        return arr;
    }
};