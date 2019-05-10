/*
4.2 Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
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
    TreeNode* buildBST(vector<int>& nums,int begin,int end){
        if(begin>end) return NULL;
        int mid=(begin+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=buildBST(nums,begin,mid-1);
        root->right=buildBST(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
};
