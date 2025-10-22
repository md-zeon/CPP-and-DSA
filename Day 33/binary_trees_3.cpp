#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(vector<int> nodes) {
    static int idx = -1;
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHeight = max(leftHeight, rightHeight) + 1;

    return currHeight;
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

void kthHelper(Node* root, int k, int currLevel) {
    if(root == NULL) {
        return;
    }

    if(currLevel == k) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currLevel+1);
    kthHelper(root->right, k, currLevel+1);
}

void kthLevel(Node* root, int k) { // O(n)
    kthHelper(root, k, 1);
    cout << endl;
}

void kthLevelWithLevelOrder(Node* root, int k) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    int currLevel = 1;

    while(!q.empty()) {
        int currSize = q.size();
        for(int i = 0; i < currSize; i++) {
            Node* currNode = q.front();
            q.pop();

            if(currLevel == k) {
                cout << currNode->data << " ";
            }

            if(currNode->left != NULL) {
                q.push(currNode->left);
            }

            if(currNode->right != NULL) {
                q.push(currNode->right);
            }
        }

        currLevel++;

        if(currLevel > k) {
            break;
        }
    }

    cout << endl;
}


bool rootToNodePath(Node* root, int n, vector<int> &path) { // O(n)
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if(root->data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2) { // TC: O(n) SC: O(n)
    vector<int> path1;
    vector<int> path2;
    
    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

Node* LCA2(Node* root, int n1, int n2) { // TC: O(n) SC: O(1)
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA == NULL) ? rightLCA : leftLCA;
} 


int dist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}


int minDistance(Node* root, int n1, int n2) {  // O(n)
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}


int kthAncestor(Node* root, int n, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = kthAncestor(root->left, n, k);
    int rightDist = kthAncestor(root->right, n, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;

    if(validVal+1 == k) {
        cout << "Kth Ancestor: " << root->data << endl;
    }

    return validVal + 1;
}


int transform(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left != NULL) {
        root->data += root->left->data;
    }

    if(root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    //! Kth level of a tree
    // kthLevel(root, 2);
    // kthLevelWithLevelOrder(root, 2);

    //! Lowest Common Ancestor

    int n1 = 4, n2 = 5; 
    // cout << "LCA = " << LCA(root, n1, n2) << endl; // LCA = 2
    // cout << "LCA 2 = " << LCA2(root, n1, n2)->data << endl; // LCA = 2


    //! Min Distance between nodes

    // cout << "Minimum Distance = " << minDistance(root, 5, 3) << endl;


    //! Kth Ancestor of a Node

    // kthAncestor(root, 6, 1); // Kth Ancestor: 3

    //! Transform to Sum Tree
    levelOrderWithNextLine(root);
    transform(root);
    levelOrderWithNextLine(root);
    

    return 0;
}