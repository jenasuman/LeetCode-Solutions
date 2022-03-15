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
    unordered_map<int,int> m;
    TreeNode* solve(vector<int>& inorder,int is,int ie,vector<int>& preorder,int ps,int pe){
        
        if(is>ie || ps>pe)return NULL;
        
        TreeNode* root=new TreeNode(preorder[ps]);
        int rootIndex=m[preorder[ps]];
        int valuesleft=rootIndex-is;
        
        root->left=solve(inorder,is,rootIndex-1,preorder,ps+1,ps+valuesleft);
        root->right=solve(inorder,rootIndex+1,ie,preorder,ps+valuesleft+1,pe);
        
        return root;
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        
        return solve(inorder,0,n-1,preorder,0,n-1);
    }
};