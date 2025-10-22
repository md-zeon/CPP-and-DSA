#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;

    }
};



Node* buildTree(vector<int> nodes) { // O(n)
    static int idx = -1;
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes); // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void preorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


void levelOrder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()) {
        Node* currNode = Q.front();
        Q.pop();

        cout << currNode->data << " ";

        if(currNode->left != NULL) {
            Q.push(currNode->left);
        }

        if(currNode->right != NULL) {
            Q.push(currNode->right);
        }
    }
}


void levelOrderWithNextLine(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* currNode = Q.front();
        Q.pop();

        if(currNode == NULL) {
            cout << endl;

            if(Q.empty()) {
                break;
            }

            Q.push(NULL); // to track next line
        } else {
            cout << currNode->data << " ";

            if(currNode->left != NULL) {
                Q.push(currNode->left);
            }

            if(currNode->right != NULL) {
                Q.push(currNode->right);
            }
        }
    }
}


int height(Node* root) { // O(n)
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHeight = max(leftHeight, rightHeight) + 1;

    return currHeight;

}

int count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int main() {
    //! Build Tree from Preorder
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes); // 1

    cout << "Root = " << root->data << endl;


    //! Tree Traversals
    cout << "Preorder Traversal: ";
    preorder(root); // 1 2 4 5 3 6
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(root); // 4 2 5 1 3 6
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root); // 4 5 2 6 3 1
    cout << endl;
    cout << "Level Order Traversal: ";
    levelOrder(root); // 1 2 3 4 5 6
    cout << endl;
    cout << "Level Order Traversal With NextLine" << endl;
    levelOrderWithNextLine(root);
    /*
        Output:
            1
            2 3
            4 5 6
    */

    //! Height of a Tree: Max distance from root to Leaf
    cout << "Height of Tree: " << height(root) << endl;

    vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    // Node* root2 = buildTree(nodes2); // 1
    // cout << "Height of Tree: " << height(root2) << endl; // 5

    //! Count of Nodes 
    cout << "Count of Nodes: " << count(root) << endl; // 6
    // cout << "Count of Nodes: " << count(root2) << endl; // 7

    //! Sum of Nodes
    cout << "Sum of Nodes: " << sum(root) << endl; // 21
    // cout << "Sum of Nodes: " << sum(root2) << endl; // 28

    return 0;
}