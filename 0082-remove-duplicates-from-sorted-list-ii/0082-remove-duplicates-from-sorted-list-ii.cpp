class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        while(head != NULL) {
            
            // If duplicate detected
            if(head->next != NULL && head->val == head->next->val) {
                
                int val = head->val;
                
                // Skip all nodes with same value
                while(head != NULL && head->val == val) {
                    head = head->next;
                }
                
                prev->next = head;
            }
            else {
                prev = head;
                head = head->next;
            }
        }
        
        return dummy->next;
    }
};
