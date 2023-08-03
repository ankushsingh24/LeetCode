class Solution {
public:
    
    vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void combination(string digits, int i, vector<string> &ans, string &temp)
    {
        if(i == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto c: mappings[digits[i] - '2'])
        {
            temp.push_back(c);
            combination(digits, i+1, ans, temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits == "")
            return {};
        
        vector<string> ans;
        string temp = "";
        
        combination(digits, 0, ans, temp);
        return ans;
    }
};