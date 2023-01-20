class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int>& nums, vector<int>& temp, int index)
    {
        if(temp.size() > 1)
            ans.push_back(temp);
        
        unordered_set<int> set;
        for(int i=index ; i<nums.size() ; i++)
        {
            if((temp.size() == 0 || temp.back() <= nums[i]) && (set.find(nums[i]) == set.end()))
            {
                temp.push_back(nums[i]);
                dfs(ans, nums, temp, i+1);
                temp.pop_back();
                set.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(ans, nums, temp, 0);
        return ans;
    }
};