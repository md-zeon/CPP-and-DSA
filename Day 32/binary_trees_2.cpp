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

int diam1(Node* root) { // O(n^2)
    if(root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}


pair<int,int> diam2(Node* root) { // O(n)
    if(root == NULL) {
        return make_pair(0, 0);
    }
    // (diameter, height)
    pair<int,int> leftInfo = diam2(root->left); // LD, LH
    pair<int,int> rightInfo = diam2(root->right); // RD, RH
    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHeight);
}

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }
    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) 
    && isIdentical(root1->right, root2->right);

    return false;
}

bool isSubTree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {
        // Identical for SubTrees
        if(isIdentical(root, subRoot)) {
            return true;
        }
    }

    bool isLeftSubTree = isSubTree(root->left, subRoot);
    if(!isLeftSubTree) {
        return isSubTree(root->right, subRoot);
    }

    return true;
}


void topView(Node* root) {

    queue<pair<Node*,int>> Q; // (Node, Horizontal Distance)
    map<int, int> m; // (HD, Node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0) { // HD is unique -> add in map
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if(currNode->right != NULL) {
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }

    for(auto i : m) {
        cout << i.second << " ";
    }
    cout << endl;
}


void bottomView(Node* root) {

    queue<pair<Node*,int>> Q; // (Node, Horizontal Distance)
    map<int, int> m; // (HD, Node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        m[currHD] = currNode->data;

        if(currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if(currNode->right != NULL) {
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }

    for(auto i : m) {
        cout << i.second << " ";
    }
    cout << endl;
}


int main() {
    // ! Diameter of a Tree: No. of nodes in the longest path between 2 leaves

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    // Approach 01 O(n^2)
    // cout << "Diameter = " << diam1(root) << endl;

    // Approach 02 O(n)
    // cout << "Diameter = " << diam2(root).first << endl;


    //! Subtree of another Tree
    //* Return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    // cout << isSubTree(root, subRoot) << endl;

    // Top view of a Tree
    topView(root);

    // Bottom view of a Tree
    bottomView(root);


    return 0;
}