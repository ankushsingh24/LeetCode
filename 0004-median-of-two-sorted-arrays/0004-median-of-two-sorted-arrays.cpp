class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        
        for(int n: nums1)
            ans.push_back(n);
        
        for(int n: nums2)
            ans.push_back(n);
        
        sort(ans.begin(), ans.end());
        
        return ans.size() % 2 ? ans[ans.size()/2] : (ans[ans.size()/2] + ans[ans.size()/2 - 1]) / 2.0;
    }
};