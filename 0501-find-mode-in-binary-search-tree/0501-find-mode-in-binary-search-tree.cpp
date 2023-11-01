/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode *node, unordered_map<int, int> &counter)
    {
        if(node == NULL)
            return;
        
        counter[node->val]++;
        dfs(node->left, counter);
        dfs(node->right, counter);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int, int> counter;
        dfs(root, counter);
        
        int maxi = 0;
        
        for(auto &[key, val] : counter)
        {
            maxi = max(maxi, val);
        }
        
        vector<int> ans;
        for(auto &[key, val] : counter)
        {
            if(val == maxi)
                ans.push_back(key);
        }
        
        return ans;
    }
};