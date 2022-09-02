import java.util.*;

import javax.crypto.Cipher;

public class l173 {

}

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

class BSTIterator {
    Stack<TreeNode> stack;
    TreeNode curNode;

    public BSTIterator(TreeNode root) {
        stack = new Stack<>();
        curNode = root;
    }

    public int next() {
        int val;
        while (curNode != null) {
            stack.push(curNode);
            curNode = curNode.left;
        }
        curNode = stack.pop();
        val = curNode.val;
        curNode = curNode.right;
        return val;
    }

    public boolean hasNext() {
        return curNode != null || !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */