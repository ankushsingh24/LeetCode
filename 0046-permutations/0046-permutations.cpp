class Solution {
public:
    void permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp)
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
                permutation(nums, ans, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        permutation(nums, ans, temp);
        return ans;
    }
};