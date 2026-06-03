#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    return (root1->data == root2->data) &&
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
}

int main() {
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    int n1, n2, value;

    cout << "Enter number of elements for BST 1: ";
    cin >> n1;

    cout << "Enter elements for BST 1: ";
    for (int i = 0; i < n1; i++) {
        cin >> value;
        root1 = insert(root1, value);
    }

    cout << "Enter number of elements for BST 2: ";
    cin >> n2;

    cout << "Enter elements for BST 2: ";
    for (int i = 0; i < n2; i++) {
        cin >> value;
        root2 = insert(root2, value);
    }

    cout << "\nInorder Traversal of BST 1: ";
    inorder(root1);

    cout << "\nInorder Traversal of BST 2: ";
    inorder(root2);

    cout << "\n\n";

    if (isIdentical(root1, root2))
        cout << "The two BSTs are identical.";
    else
        cout << "The two BSTs are not identical.";

    return 0;
}