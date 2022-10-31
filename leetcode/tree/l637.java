package leetcode.tree;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class l637 {
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<Double> res = new LinkedList<>();
        queue.offer(root);
        while (queue.size() != 0) {
            long curLen = queue.size();
            TreeNode curNode;
            long total = 0;
            for (int i = 0; i < curLen; i++) {
                curNode = queue.poll();
                if (curNode.left != null)
                    queue.offer(curNode.left);
                if (curNode.right != null)
                    queue.offer(curNode.right);
                total += curNode.val;
            }
            res.add((double) total / curLen);
        }
        return res;
    }
}
