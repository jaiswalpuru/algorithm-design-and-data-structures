public class Main {
    public static void main(String[] args) {
        BinarySearchTree root = new BinarySearchTree(40);
        root.insert(60);
        root.insert(20);
        root.insert(80);
        root.insert(50);
        root.insert(10);
        root.insert(30);
        root.insert(15);
        root.insert(5);
        root.insert(35);
        root.insert(25);
        root.insert(45);
        root.insert(55);
        root.insert(70);
        root.insert(90);
        root.insert(32);
        root.insert(33);
        root.insert(48);
        root.insert(46);
        System.out.println("Inorder Traversal");
        root.inorder();
        System.out.println("\n\n");
        System.out.println("Delete Node 40");
        root.delete(40);
        System.out.println("Inorder traversal after deleting 40");
        root.inorder();
        System.out.println("\n\n");
        System.out.println("Delete Node 20");
        root.delete(20);
        System.out.println("Inorder traversal after deleting 20");
        root.inorder();
        System.out.println("\n\n");
    }
}
