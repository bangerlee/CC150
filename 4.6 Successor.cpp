/*
4.6 Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* p=NULL;
        if(node->right==NULL){
            p=node->parent;
            while(p!=NULL&&p->val<=node->val) p=p->parent;
        }
        else{
            p=node->right;
            while(p->left!=NULL) p=p->left;
        }
        return p;
    }
};
