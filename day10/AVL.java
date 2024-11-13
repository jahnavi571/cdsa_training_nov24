class AVLTree {

    // Node structure
    static class Node {
        int key;
        Node left, right;
        int height;

        public Node(int key) {
            this.key = key;
            this.height = 1;
        }
    }

    private Node root;

    // Get the height of the node
    private int height(Node node) {
        return node == null ? 0 : node.height;
    }

    // Get the balance factor of the node
    private int getBalanceFactor(Node node) {
        return node == null ? 0 : height(node.left) - height(node.right);
    }

    // Right rotation (single)
    private Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Update heights
        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        // Return new root
        return x;
    }

    // Left rotation (single)
    private Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        // Update heights
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        // Return new root
        return y;
    }

    // Left-Right rotation (double)
    private Node leftRightRotate(Node node) {
        node.left = leftRotate(node.left);
        return rightRotate(node);
    }

    // Right-Left rotation (double)
    private Node rightLeftRotate(Node node) {
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    // Insert a key into the AVL tree and balance the tree
    public Node insert(Node node, int key) {
        // 1. Perform the normal BST insertion
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        // 2. Update height of this ancestor node
        node.height = 1 + Math.max(height(node.left), height(node.right));

        // 3. Get the balance factor of this node (to check whether it became unbalanced)
        int balance = getBalanceFactor(node);

        // 4. If the node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node.left.key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node.right.key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node.left.key) {
            return leftRightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node.right.key) {
            return rightLeftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Public method to start the insertion
    public void insert(int key) {
        root = insert(root, key);
    }

    // Inorder traversal of the AVL tree (prints sorted values)
    public void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);
        }
    }

    public void inorder() {
        inorder(root);
    }

    // Search for a key in the AVL tree
    public Node search(Node root, int key) {
        // Base Cases: root is null or key is present at the root
        if (root == null || root.key == key) {
            return root;
        }

        // Key is greater than root's key
        if (key > root.key) {
            return search(root.right, key);
        }

        // Key is smaller than root's key
        return search(root.left, key);
    }

    public boolean search(int key) {
        return search(root, key) != null;
    }

    // Delete a key from the AVL tree (and rebalance)
    public Node delete(Node root, int key) {
        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == null) {
            return root;
        }

        // If the key to be deleted is smaller than the root's key, go to the left subtree
        if (key < root.key) {
            root.left = delete(root.left, key);
        }
        // If the key to be deleted is larger than the root's key, go to the right subtree
        else if (key > root.key) {
            root.right = delete(root.right, key);
        }
        // Key is the same as root's key, this is the node to be deleted
        else {
            // Node with only one child or no child
            if (root.left == null || root.right == null) {
                Node temp = root.left != null ? root.left : root.right;

                // No child case
                if (temp == null) {
                    root = null;
                } else {
                    // One child case
                    root = temp;
                }
            }
            // Node with two children
            else {
                // Get the inorder successor (smallest in the right subtree)
                Node temp = minValueNode(root.right);

                // Copy the inorder successor's content to this node
                root.key = temp.key;

                // Delete the inorder successor
                root.right = delete(root.right, temp.key);
            }
        }

        // If the tree had only one node, then return
        if (root == null) {
            return root;
        }

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root.height = Math.max(height(root.left), height(root.right)) + 1;

        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether it became unbalanced)
        int balance = getBalanceFactor(root);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root.left) >= 0) {
            return rightRotate(root);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root.left) < 0) {
            return leftRightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root.right) <= 0) {
            return leftRotate(root);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root.right) > 0) {
            return rightLeftRotate(root);
        }

        return root;
    }

    // Public delete method
    public void delete(int key) {
        root = delete(root, key);
    }

    // Utility function to find the node with minimum value
    private Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    // Print the AVL tree inorder (sorted)
    public void printInorder() {
        inorder(root);
        System.out.println();
    }

    // Main method to test the AVL tree
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();

        tree.insert(10);
        tree.insert(20);
        tree.insert(30);
        tree.insert(15);
        tree.insert(25);
        tree.insert(5);

        System.out.println("Inorder traversal of the AVL tree:");
        tree.printInorder();

        // Searching
        System.out.println("Search for 15: " + (tree.search(15) ? "Found" : "Not Found"));
        System.out.println("Search for 100: " + (tree.search(100) ? "Found" : "Not Found"));

        // Deletion
        tree.delete(15);
        System.out.println("Inorder traversal after deletion of 15:");
        tree.printInorder();
    }
}

