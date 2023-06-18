class Solution {
public:
    void subsets(vector<vector<int>> &res, vector<int> &nums, vector<int> &vec, int begin)
    {
        res.push_back(vec);
        for(int i=begin ; i != nums.size() ; i++)
        {
            vec.push_back(nums[i]);
            subsets(res, nums, vec, i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vec;
        
        subsets(res, nums, vec, 0);
        return res;
    }
};