/*
4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
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
    bool judgeBlanced(TreeNode* root,int& depth){
        if(root==0){depth=0; return true;}
        int left=0,right=0;
        bool lt=judgeBlanced(root->left,left);
        bool rt=judgeBlanced(root->right,right);
        if(lt&&rt&&abs(left-right)<=1){
            depth=max(left,right)+1;
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth=0;
        return judgeBlanced(root,depth);
    }
};
