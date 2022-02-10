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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        
        //base condition
        if(!root) return ans;
        //DFS  
        level(root, ans);
        return ans;
        
    }
    
    //calculate level of each node + insert nodes in ans 
    int level(TreeNode* root, vector<vector<int>> &ans)
    {
        if(!root) return -1;
        int height = max(level(root->left, ans), level(root->right, ans)) + 1;
        if(ans.size() <= height)
        {
            ans.push_back({});
        }
        ans[height].push_back(root->val);
        return height;
        
    }
};