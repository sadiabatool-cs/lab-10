#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t) {
        isbn = i;
        title = t;
        left = nullptr;
        right = nullptr;
    }
};

struct ListNode {
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t) {
        isbn = i;
        title = t;
        next = nullptr;
    }
};

BSTNode* insert(BSTNode* root, int isbn, string title) {
    if (root == nullptr)
        return new BSTNode(isbn, title);

    if (isbn < root->isbn)
        root->left = insert(root->left, isbn, title);
    else if (isbn > root->isbn)
        root->right = insert(root->right, isbn, title);

    return root;
}

void bstToLinkedList(BSTNode* root, ListNode*& head, ListNode*& tail) {
    if (root == nullptr)
        return;

    bstToLinkedList(root->left, head, tail);

    ListNode* newNode = new ListNode(root->isbn, root->title);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    bstToLinkedList(root->right, head, tail);
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << "ISBN: " << head->isbn
            << ", Title: " << head->title << endl;
        head = head->next;
    }
}

int main() {
    BSTNode* root = nullptr;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int n, isbn;
    string title;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter ISBN: ";
        cin >> isbn;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        root = insert(root, isbn, title);
    }

    bstToLinkedList(root, head, tail);

    cout << "\nLibrary Catalog (Sorted by ISBN):\n";
    printList(head);

    return 0;
}