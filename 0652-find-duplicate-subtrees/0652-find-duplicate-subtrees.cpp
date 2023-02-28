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
    unordered_map<string, int> map;
    vector<TreeNode *> ans;
    
    string solve(TreeNode* root)
    {
        if(root == NULL)
            return "";
        
        string l = solve(root->left);
        string r = solve(root->right);
        string s = "(" + l + to_string(root->val) + r + ")";  //make unique string of each subtree
         
        if(map[s] != -1)
            map[s]++;  // if string is not present insert and increase count
        
        if(map[s] > 1)  // if same string found more than one time we got same subtrees
        {
            ans.push_back(root);
            map[s] = -1;  // no need to insert again
        }
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        solve(root);
        return ans;
    }
};