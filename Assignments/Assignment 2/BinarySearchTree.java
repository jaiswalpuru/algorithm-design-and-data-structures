public class BinarySearchTree {
    TreeNode node;
    BinarySearchTree(int val) {
        this.node = new TreeNode(val);
    }
    
    public void insert(int val) {
        TreeNode newNode = new TreeNode(val);
        if (this.node == null) {
            this.node = newNode;
        }
        TreeNode root = this.node;
        _insert(root, val);
    }

    private TreeNode _insert(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val < val) {
            root.right = _insert(root.right, val);
            if (root.right == null) {
                root.right = new TreeNode(val);
            }
        }else {
            root.left = _insert(root.left, val);
            if (root.left == null) {
                root.left = new TreeNode(val);
            }
        }
        return root;
    }

    public void inorder() {
        TreeNode root = this.node;
        _inorder(root);
    }

    private void _inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        _inorder(root.left);
        System.out.print(root.val + "  " );
        _inorder(root.right);
    }

    public void delete(int val) {
        TreeNode root = this.node;
        this.node = _delete(root, val);
    }

    public TreeNode _delete(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val > val) {
            root.left = _delete(root.left, val);
        } else if (root.val < val) {
            root.right = _delete(root.right, val);
        }else {
            if (root.left == null && root.right == null) {
                root = null;
            }else if (root.right != null) {
                root.val = successor(root);
                root.right = _delete(root.right, root.val);
            }else {
                root.val = predecessor(root);
                root.left = _delete(root.left, root.val);
            }
        }
        return root;
    }

    private int predecessor(TreeNode root) {
        root = root.left;
        while (root.right != null) {
            root = root.right;
        }
        return root.val;
    }

    private int successor(TreeNode root) {
        root = root.right;
        while(root.left != null) {
            root = root.left;
        }
        return root.val;
    }
}
