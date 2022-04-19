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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL)return;
        
        inorder(root->left);
        
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        //There could be adjacent violations or non-adjacent violations
        //if last is NULL then there is adjacent violation else swap the first and last 
        if(last!=NULL){
            swap(last->val,first->val);
        }
        else swap(first->val,middle->val);
    }
};