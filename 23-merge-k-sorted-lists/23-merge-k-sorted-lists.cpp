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
    ListNode* mergeTwoList(ListNode* a,ListNode* b){
        
        if(a==NULL)return b;
        if(b==NULL)return a;
        
        if(a->val<=b->val){
            a->next=mergeTwoList(a->next,b);
            return a;
        }
        
        else{
            
            b->next=mergeTwoList(a,b->next);
            return b;
            
        }
        
 
        
        
        
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
       if(lists.empty())return NULL;
       
       int len=lists.size(); 
        
       while(len>1){
           
          for(int i=0;i<len/2;i++){
              lists[i]=mergeTwoList(lists[i],lists[len-i-1]);
          }
           len=(len+1)/2;
        }
        
        
        return lists.front();
        
     
        
    }
};