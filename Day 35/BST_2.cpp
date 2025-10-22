#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* sortedArrayToBalancedBST(vector<int> &v, int si, int ei) {
    if(si > ei) {
        return NULL;
    }

    int mid = (si + ei) / 2;

    Node* root = new Node(v[mid]);
    root->left = sortedArrayToBalancedBST(v, si, mid-1);
    root->right = sortedArrayToBalancedBST(v, mid+1, ei);

    return root;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void BSTToSortedArray(Node* root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    BSTToSortedArray(root->left, v);
    v.push_back(root->data);
    BSTToSortedArray(root->right, v);
}


class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;
    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxSize;

Info* largestBst(Node* root) {
    // Base Case:
    // if(root == NULL) {
    //     return new Info(true, INT_MAX, INT_MIN, 0);
    // }

    // We can also use this base case
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBst(root->left);
    Info* rightInfo = largestBst(root->right);
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->size + rightInfo->size + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min) {
        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}


int main() {
    //! Sorted Array to Balanced BST
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9};

    Node* root = sortedArrayToBalancedBST(arr, 0, arr.size()-1);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;

    //! Convert BST to Balanced BST
    vector<int> v;
    Node* root2 = new Node(6);
    root2->left = new Node(5);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(3);
    root2->right = new Node(7);
    root2->right->right = new Node(8);
    root2->right->right->right = new Node(9);

    BSTToSortedArray(root2, v);
    root2 = sortedArrayToBalancedBST(v, 0, v.size()-1);
    preOrder(root2);

    //! Size Of Largest BST in Binary Tree

    Node* root3 = new Node(50);
    root3->left = new Node(30);
    root3->left->left = new Node(5);
    root3->left->right = new Node(20);

    root3->right = new Node(60);
    root3->right->left = new Node(45);
    root3->right->right = new Node(70);
    root3->right->right->left = new Node(65);
    root3->right->right->right = new Node(80);

    largestBst(root3);

    cout << "Maximum Size: " << maxSize << endl;


    //! Merge 2 BSTs

    Node* bst1 = new Node(2);
    bst1->left = new Node(1);
    bst1->right = new Node(4);

    Node* bst2 = new Node(9);
    bst2->left = new Node(3);
    bst2->right = new Node(12);

    vector<int> bstSequence;

    BSTToSortedArray(bst1, bstSequence);
    BSTToSortedArray(bst2, bstSequence);
    sort(bstSequence.begin(), bstSequence.end());

    Node* bst = sortedArrayToBalancedBST(bstSequence, 0, bstSequence.size()-1);


    return 0;
}