import java.util.*;

public class l113 {

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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new LinkedList<>();
        Stack<Integer> curList = new Stack<>();
        helper(root, 0, targetSum, curList, res);
        return res;
    }

    public void helper(TreeNode node, int curSum, int targetSum,
            Stack<Integer> curList, List<List<Integer>> res) {
        if (node == null)
            return;
        curSum += node.val;
        curList.push(node.val);
        if (node.left == null && node.right == null && curSum == targetSum) {
            res.add(new LinkedList<>(curList));
        }
        helper(node.left, curSum, targetSum, curList, res);
        helper(node.right, curSum, targetSum, curList, res);
        curList.pop();
    }
}