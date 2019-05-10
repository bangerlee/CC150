/*
4.12 Paths with Sum: You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value.The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
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
    int sumup(TreeNode* root,int pre,int sum){
        if(root==NULL) return 0;
        int cur=pre+root->val;
        return (cur==sum)+sumup(root->left,cur,sum)+sumup(root->right,cur,sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return sumup(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
