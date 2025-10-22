#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* insert(Node* root, int val) { //O(log n)
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data) { // left subtree
        root->left = insert(root->left, val);
    } else { // right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) { //O(nlogn)
    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) { // left subtree
        return search(root->left, key);
    } else { // right subtree
        return search(root->right, key);
    }
}


Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root; // IS
}


Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if(val < root->data) { // left subtree
        root->left = deleteNode(root->left, val);
    } else if(val > root->data) { // right subtree
        root->right = deleteNode(root->right, val);
    } else {
        // Found the node to be deleted
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) { 
            delete root;
            return NULL;
        }

        // Case 2: One child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }

        // Case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data); // case1, case2

        return root;
    }

    return root;
}

void printInRange(Node* root, int start, int end) {
    if (root == NULL) {
        return;
    }

    if(root->data >= start && root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data < start) {
        printInRange(root->right, start, end);
    } else {
        printInRange(root->left, start, end);
    }
} 


void pathHelper(Node* root, vector<int> &path) {
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        cout << "Path: ";
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();
}

void rootToNodePath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

bool validateHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if (min != NULL && root->data < min->data) {
        return false;
    }

    if (max != NULL && root->data > max->data) {
        return false;
    }

    return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}

bool isValidBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}


int main() {

    //! Build a BST
    // int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    // Node* root1 = buildBST(arr, 6);
    Node* root = buildBST(arr2, 9);

    // inOrder(root1); // 1 2 3 4 5 7
    // inOrder(root); // 1 3 4 5 6 8 10 11 14 
    // cout << endl;


    //! Search in BST
    // cout << search(root, 15) << endl;

    //! Delete a Node
    inOrder(root); // 1 3 4 5 6 8 10 11 14 
    root = deleteNode(root, 10);
    cout << endl;
    inOrder(root); // 1 3 4 5 6 8 11 14 

    //! Print in Range
    cout << endl;
    printInRange(root, 5, 12);

    //! Root to Leaf Path
    cout << endl;
    rootToNodePath(root);

    //! Validate BST (***)
    if(isValidBST(root)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}