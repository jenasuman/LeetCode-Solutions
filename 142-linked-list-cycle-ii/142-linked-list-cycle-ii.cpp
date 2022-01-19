/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)return NULL;
        
        ListNode* slow=head;
        
        unordered_set<ListNode*> s;
        
        while(slow){
            if(s.find(slow)!=s.end()){
                break;
            }
            s.insert(slow);
            slow=slow->next;
        }
        
        return slow;
    }
};