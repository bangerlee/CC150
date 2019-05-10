/*
4.5 Validate 8ST: Implement a function to check ifa binary tree is a binary search tree.
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
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return true;
        TreeNode* prev=NULL;
        while(root!=NULL||!st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(prev!=NULL&&prev->val>=root->val) return false;
            prev=root;
            root=root->right;
        }
        return true;
    }
};
