class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> map;
        vector<int> output;
        
        for(auto i: nums)
        {
            map[i]++;
        }
        
        for(auto i: map)
        {
            if(i.second > nums.size() / 3)
                output.push_back(i.first);
        }
        
        return output;
    }
};