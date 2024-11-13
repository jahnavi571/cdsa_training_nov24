// Node class to represent a node in the BST
class Node {
    int data;
    Node left, right;

    // Constructor to create a new node
    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

// Binary Search Tree class
class BST {
    private Node root;

    // Constructor to initialize the root of the BST
    public BST() {
        root = null;
    }

    // Method to insert a value into the BST
    public void insert(int data) {
        root = insertRec(root, data);
    }

    // Helper method for recursive insertion
    private Node insertRec(Node root, int data) {
        // If the tree is empty, return a new node
        if (root == null) {
            root = new Node(data);
            return root;
        }

        // Otherwise, recur down the tree
        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        // Return the (unchanged) node pointer
        return root;
    }

    // Method to search for a value in the BST
    public boolean search(int data) {
        return searchRec(root, data);
    }

    // Helper method for recursive search
    private boolean searchRec(Node root, int data) {
        // Base case: root is null or data is present at the root
        if (root == null) {
            return false;
        }
        if (root.data == data) {
            return true;
        }

        // Data is greater than the root's data
        if (data < root.data) {
            return searchRec(root.left, data);
        }

        // Data is smaller than the root's data
        return searchRec(root.right, data);
    }

// Method to perform an in-order traversal

