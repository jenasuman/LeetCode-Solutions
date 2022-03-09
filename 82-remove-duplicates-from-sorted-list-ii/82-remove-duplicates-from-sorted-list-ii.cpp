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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* prev=new ListNode(-1);
        ListNode* curr=head;
        prev->next=head;
        ListNode* start=prev;
        
        while(curr){
         
            if(curr->next && curr->val==curr->next->val){
                
                while(curr->next && curr->val==curr->next->val)curr=curr->next;
                
                curr=curr->next;
                prev->next=curr;
                
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
            
            
            
        }
        
        
        return start->next;
    }
};