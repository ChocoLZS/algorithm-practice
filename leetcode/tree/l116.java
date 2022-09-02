public class l116 {

}

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    public Node connect(Node root) {
        if (root != null) {
            Node curNode = root;
            while (curNode.left != null) {
                Node nextLevelNode = curNode;
                while (nextLevelNode != null) {
                    nextLevelNode.left.next = nextLevelNode.right;
                    if (nextLevelNode.next != null) {
                        nextLevelNode.right.next = nextLevelNode.next.left;
                    }
                    nextLevelNode = nextLevelNode.next;
                }
                curNode = curNode.left;
            }
        }

        return root;
    }
}