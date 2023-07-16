class Solution {
public:
    void backtrack(vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int num: nums)
        {
            if(find(temp.begin(), temp.end(), num) == temp.end())
            {
                temp.push_back(num);
                backtrack(temp, ans, nums);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        backtrack(temp, ans, nums);
        return ans;
    }
};