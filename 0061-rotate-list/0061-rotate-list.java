class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0){
            return head;
        }

        ListNode curr = head;
        int n = 1;

        while(curr.next != null){
            curr = curr.next;
            n++;
        }

        k = k % n;
        if(k == 0){
            return head;
        }

        curr.next = head;
        ListNode tail = head;
        int steps = n - k;

        for(int i=1; i<steps; i++){
            tail = tail.next;
        }

        ListNode newHead = tail.next;
        tail.next = null;

        return newHead;
    }
}