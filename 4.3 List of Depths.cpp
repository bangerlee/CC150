/*
4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have Dlinked lists).
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void helper(vector<vector<int>>& res,TreeNode* root,int level){
        if(root==NULL) return;
        if(level==res.size()) res.push_back(vector<int>(0));
        res[level].push_back(root->val);
        helper(res,root->left,level+1);
        helper(res,root->right,level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(res,root,0);
        return res;
    }
};
