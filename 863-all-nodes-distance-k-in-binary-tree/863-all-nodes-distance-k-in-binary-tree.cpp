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
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            
               if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
            
            
        }
        
        
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> parent;
        
        markParent(root,parent,target);
        
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target]=true;
        
        int curr_level=0;
        
        while(!q.empty()){
            
            int n=q.size();
            
            if(curr_level==k)break;
            
            curr_level++;
            
            for(int i=0;i<n;i++){
                
                TreeNode* curr=q.front();
                q.pop();
                
                
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
                
                
                
            }
            
              
            
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            ans.push_back(t->val);
        }
        return ans;
    }
};