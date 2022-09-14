package leetcode.linklist;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class l21 {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode root = null, list1Crawl = list1, list2Crawl = list2, tail = null;
        if (list1Crawl == null || list2Crawl == null)
            return list1Crawl == null ? list2Crawl : list1Crawl;
        if (list1Crawl.val < list2Crawl.val) {
            root = list1Crawl;
            list1Crawl = list1Crawl.next;
        } else {
            root = list2Crawl;
            list2Crawl = list2Crawl.next;
        }
        tail = root;
        while (list1Crawl != null && list2Crawl != null) {
            if (list1Crawl.val < list2Crawl.val) {
                tail.next = list1Crawl;
                list1Crawl = list1Crawl.next;
            } else {
                tail.next = list2Crawl;
                list2Crawl = list2Crawl.next;
            }
            tail = tail.next;
        }
        while (list1Crawl != null) {
            tail.next = list1Crawl;
            tail = tail.next;
            list1Crawl = list1Crawl.next;
        }
        while (list2Crawl != null) {
            tail.next = list2Crawl;
            tail = tail.next;
            list2Crawl = list2Crawl.next;
        }
        return root;
    }
}
