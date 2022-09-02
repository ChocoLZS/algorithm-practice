import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    // iteration with stack
    // public void flatten(TreeNode root) {
    // Stack<TreeNode> stack = new Stack<>();
    // List<TreeNode> list = new LinkedList<>();
    // if (root != null) {
    // stack.push(root);
    // while (!stack.isEmpty()) {
    // TreeNode curNode = stack.pop();
    // list.add(curNode);
    // if (curNode.right != null)
    // stack.push(curNode.right);
    // if (curNode.left != null)
    // stack.push(curNode.left);
    // }
    // TreeNode preNode = root;
    // for (int i = 1; i < list.size(); i++) {
    // TreeNode curNode = list.get(i);
    // preNode.left = null;
    // preNode.right = curNode;
    // preNode = curNode;
    // }
    // }
    // }
    public void flatten(TreeNode root) {
        TreeNode curNode = root;
        while (curNode != null) {
            if (curNode.left != null) {
                TreeNode next = curNode.left;
                TreeNode prev = next;
                while (prev.right != null) {
                    prev = prev.right;
                }
                prev.right = curNode.right;
                curNode.left = null;
                curNode.right = next;
            }
            curNode = curNode.right;

        }
    }
}