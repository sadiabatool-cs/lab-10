#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (head == NULL) {
        cout << endl;
        return;
    }

    cout << head->data << " ";
    printList(head->next);
}

Node* insertBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    return newNode;
}

Node* insertEnd(Node* head, int value) {
    if (head == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

    head->next = insertEnd(head->next, value);
    return head;
}

Node* insertPosition(Node* head, int value, int pos) {
    if (pos < 1) {
        cout << "Invalid Position" << endl;
        return head;
    }

    if (pos == 1) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        return newNode;
    }

    if (head == NULL) {
        cout << "Invalid Position" << endl;
        return head;
    }

    head->next = insertPosition(head->next, value, pos - 1);
    return head;
}

Node* deleteValue(Node* head, int value) {
    if (head == NULL) {
        cout << "Value not found" << endl;
        return NULL;
    }

    if (head->data == value) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, value);
    return head;
}

Node* deletePosition(Node* head, int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid Position" << endl;
        return head;
    }

    if (pos == 1) {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletePosition(head->next, pos - 1);
    return head;
}

int search(Node* head, int value, int pos = 1) {
    if (head == NULL)
        return -1;

    if (head->data == value)
        return pos;

    return search(head->next, value, pos + 1);
}

int main() {
    Node* head = NULL;

    head = insertBeginning(head, 10);
    printList(head);

    head = insertBeginning(head, 5);
    printList(head);

    head = insertEnd(head, 20);
    printList(head);

    head = insertPosition(head, 15, 3);
    printList(head);

    head = deleteValue(head, 10);
    printList(head);

    head = deletePosition(head, 2);
    printList(head);

    int result = search(head, 20);

    if (result != -1)
        cout << "Value found at position: " << result << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}