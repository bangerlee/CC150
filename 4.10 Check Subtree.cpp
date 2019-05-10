/*
4.10 Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an a l g o r i t h m t o d e t e r m i n e i f T 2 is a s u b t r e e o f T l .
A tree T2 is a subtree of T1 if there exists a node n in Tl such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
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
    bool isSame(TreeNode* s,TreeNode* t){
        if(s==NULL&&t==NULL) return true;
        if(s==NULL||t==NULL) return false;
        if(s->val!=t->val) return false;
        return isSame(s->left,t->left) && isSame(s->right,t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;
        if(isSame(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
