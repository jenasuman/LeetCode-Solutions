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
class BSTIterator {
    TreeNode* newRoot;
    TreeNode* head;
public:
    
    BSTIterator(TreeNode* root) {
        newRoot=new TreeNode(-1);
        head=newRoot;
        inorder(root);
        
        
    }
    void inorder(TreeNode* root){
        if(root==NULL)return;
        
        inorder(root->left);
        
        TreeNode* temp=new TreeNode(root->val);
        newRoot->right=temp;
        newRoot=newRoot->right;
        
        inorder(root->right);
        
        
        
    }
    int next() {
        if(hasNext())
        {
           head=head->right;
           return head->val; 
        } 
        return -1;
    }
    
    bool hasNext() {
        return head->right;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */