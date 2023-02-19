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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        
        if(root == NULL)
            return ans;
        
        q.push(root);
        bool flag = false;
        
        while(!q.empty())
        {
            vector<int> temp;
            int s = q.size();
            
            while(s--)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                
                temp.push_back(node->val);
            }
            
            if(flag == false)
            {
                ans.push_back(temp);
                flag = true;
            }
            
            else
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                flag = false;
            }
        }
        
        return ans;
    }
};