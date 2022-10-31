import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class l817 {
    static final int stateExist = 0;
    static final int stateNone = 1;
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        ListNode cur = head;
        int total = 0;
        int state = stateExist;
        if (set.contains(head.val)) {
            state = stateExist;
            total = total + 1;
        } else {
            state = stateNone;
        }
        cur = head.next;
        while (cur != null) {
            switch (state) {
                case stateNone:
                    if (set.contains(cur.val)) {
                        state = stateExist;
                        total = total + 1;
                    }
                    break;
                case stateExist:
                    if (!set.contains(cur.val)) {
                        state = stateNone;
                    }
                    break;
            }
            cur = cur.next;
        }
        return total;
    }
    
}
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
