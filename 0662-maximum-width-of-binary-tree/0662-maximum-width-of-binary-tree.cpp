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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int n = q.size();
            long long last = q.back().second;
            long long front = q.front().second;
            
            for(int i=0 ; i<n ; i++)
            {
                TreeNode *temp = q.front().first;
                long long idx = q.front().second;
                q.pop();
                
                if(temp->left != NULL)
                    q.push({temp->left, idx*2+1});
                if(temp->right != NULL)
                    q.push({temp->right, idx*2+2});
            }
            
            ans = max(ans, last - front + 1);
        }
        
        return ans;
    }
};