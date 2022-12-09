public class Node {
    int val;
    Node next;
    public Node(int val) { this.val = val; }
    public void addToLEnd(int val) {
        Node end = new Node(val);
        Node n = this;
        while(n.next != null) n = n.next;
        n.next = end;
    }
}
