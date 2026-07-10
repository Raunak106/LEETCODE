import java.util.*;

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ArrayList<Integer> a = new ArrayList<>();

        for (; l1 != null; l1 = l1.next) a.add(l1.val);
        for (; l2 != null; l2 = l2.next) a.add(l2.val);

        if (a.size() == 0) return null;

        Collections.sort(a);

        ListNode h = new ListNode(a.get(0)), t = h;
        for (int i = 1; i < a.size(); i++)
            t = t.next = new ListNode(a.get(i));

        return h;
    }
}
