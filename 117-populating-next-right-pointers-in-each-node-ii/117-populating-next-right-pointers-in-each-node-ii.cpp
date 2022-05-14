/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        
      Node* curr=root;
        
      while(curr){
          
          Node* head=NULL;
          Node* temp=NULL;
          
       while(curr){   
          
          if(curr->left){
             
              if(!head){
                  head=curr->left;
                  temp=head;
              }
              else{
                  temp->next=curr->left;
                  temp=temp->next;
              }
              
              
          }
            if(curr->right){
             
              if(!head){
                  head=curr->right;
                  temp=head;
              }
              else{
                  temp->next=curr->right;
                  temp=temp->next;
              }
              
              
          }
          
          curr=curr->next;
          
      }
          
          curr=head;
          
          
      }  
        
        
        
        return root;
        
    }
};