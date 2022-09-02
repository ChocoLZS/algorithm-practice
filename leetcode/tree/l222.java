import java.util.*;

public class l222 {

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
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        int curNodeIndex = 1;
        TreeNode curNode = root;
        while (curNode.left != null || curNode.right != null) {
            if (curNode.right != null) {
                curNode = curNode.right;
                curNodeIndex = curNodeIndex * 2 + 1;
            } else if (curNode.left != null) {
                curNodeIndex = curNodeIndex * 2;
                break;
            }
        }
        return curNodeIndex;
    }

    public int getHeight(TreeNode root) {
        int level = 1;
        while (root != null) {
            root = root.left;
            level += 1;
        }
        return level;
    }
}