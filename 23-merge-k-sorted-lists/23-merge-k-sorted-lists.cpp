/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    using p=pair<int,ListNode*>;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
          priority_queue<p,vector<p>,greater<p>> pq;
          for(auto r:lists){
              if(r!=NULL)
              pq.emplace(r->val,r);
          }
        
          ListNode* root=NULL;
          ListNode* prev=NULL;
        
          while(!pq.empty()){
              
              auto [value,currNode]=pq.top();
              pq.pop();
              
              ListNode* temp=new ListNode(value);
              
              if(root==NULL){
                  root=temp;
                  prev=temp;
              }
              else{
                  prev->next=temp;
                  prev=temp;
              }
              
              if(currNode->next){
                  
                  currNode=currNode->next;
                  value=currNode->val;
                  pq.emplace(value,currNode);
                  
              }
              
              
              
              
              
              
              
              
              
              
          }
        return root;
        
    }
};