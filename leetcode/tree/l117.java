public class l117 {

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
        Node curNode = root;
        while (curNode != null && (curNode.left != null || curNode.right != null)) {
            Node prevNode = curNode;
            while (prevNode != null) {
                if (prevNode.left != null)
                    prevNode.left.next = prevNode.right == null
                            ? getLeftChildNode(prevNode.next)
                            : prevNode.right;
                if (prevNode.right != null)
                    prevNode.right.next = getLeftChildNode(prevNode.next);
                prevNode = prevNode.next;
            }
            curNode = getNotLeafChildNode(curNode);
        }
        return root;
    }

    public Node getLeftChildNode(Node node) {
        while (node != null) {
            if (node.left != null || node.right != null) {
                return node.left == null ? node.right : node.left;
            }
            node = node.next;
        }
        return null;
    }

    public Node getNotLeafChildNode(Node node) {
        Node child = node.left == null ? node.right : node.left;
        while (child != null && child.left == null && child.right == null)
            child = child.next;
        return child;
    }
}