import java.util.*;

public class l199 {

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

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        Deque<TreeNode> queue = new LinkedList<>();
        Queue<TreeNode> curQueue = new LinkedList<>();
        if (root == null)
            return res;
        TreeNode curNode = root;
        queue.offer(curNode);
        while (!queue.isEmpty()) {
            curQueue.addAll(queue);
            res.add(queue.getLast().val);
            queue.clear();
            for (TreeNode node : curQueue) {
                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
            }
            curQueue.clear();
        }
        return res;
    }

}