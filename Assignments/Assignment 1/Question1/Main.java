import java.util.Random;

public class Main{
    public static void main(String[] args) {
        Node n = new Node(20);
        addNodes(n);
        int len = count(n);
        System.out.println("Before Sorting");
        printList(n);
        Node sortList = selectionSort(n);
        System.out.println("After Sorting");
        printList(sortList);
    }

    public static void printList(Node n) {
        while(n.next != null) {
            System.out.print(n.val+"->");
            n=n.next;
        }
        System.out.println(n.val);
    }

    public static Node selectionSort(Node n) { 
        if (n.next == null) {
            return n;
        }
        Node minNode = n;
        Node minPrev = null;
        for(Node ptr = n; ptr.next != null; ptr=ptr.next) {
            if (ptr.next.val < minNode.val){
                minNode = ptr.next;
                minPrev = ptr;
            }
        }
        if (minNode != n) {
           n = swapNodes(n, n, minNode, minPrev);
        }
        n.next = selectionSort(n.next);
        return n;
    }

    public static Node swapNodes(Node headRef, Node currOne, Node currTwo, Node prev) {
        headRef = currTwo;
        prev.next = currOne;
        Node temp = currTwo.next;
        currTwo.next = currOne.next;
        currOne.next = temp;
        return headRef;
    }

    public static Node bubbleSort(Node n) {
        Node senti = new Node(-1);
        senti.next = n;
        int len = count(n);
        for(int i=0;i<len;i++){
            Node curr=senti.next;
            Node prev = senti;
            while (curr.next != null){
                if (curr.val > curr.next.val) {
                    Node currTemp = curr;
                    Node nextTemp = curr.next;
                    prev.next = nextTemp;
                    currTemp.next = nextTemp.next;
                    nextTemp.next = curr;
                    curr = prev.next;
                }else {
                    prev = curr;
                    curr = curr.next;
                }
            }
        }
        return senti.next;
    }

    public static void addNodes(Node n) {
        Random rand = new Random();
        for (int i=0;i<20;i++){
            n.addToLEnd(rand.nextInt(50));
        }
    }

    public static int count(Node n) {
        int cnt = 0;
        while(n!=null) {
            n = n.next;
            cnt++;
        }
        return cnt;
    }
}
