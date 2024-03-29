
// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


// Definition for a binary tree node.
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


function sortedListToBST(head: ListNode | null): TreeNode | null {
    if (head == null) return null;
    let fast: ListNode, slow: ListNode, prev: ListNode;
    fast = slow = prev = head;
    //crawling
    while (fast.next !== null && fast.next.next !== null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    while (prev != slow && prev.next != slow) {
        prev = prev.next
    }
    let root = new TreeNode(slow.val);
    if (prev != slow) {
        prev.next = null;
        root.left = sortedListToBST(head);
    }
    root.right = sortedListToBST(slow.next);
    return root;
};
