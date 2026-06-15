class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            return nullptr;
        }
        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;

        for (int i = 0; i < n / 2 - 1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};