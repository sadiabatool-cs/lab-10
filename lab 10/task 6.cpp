#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

    Node* insertEndRec(Node* temp, int val) {
        if (temp == NULL) {
            return new Node(val);
        }

        if (temp->next == NULL) {
            Node* newNode = new Node(val);
            temp->next = newNode;
            newNode->prev = temp;
            return temp;
        }

        insertEndRec(temp->next, val);
        return temp;
    }

    void printForwardRec(Node* temp) {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        printForwardRec(temp->next);
    }

    void printReverseRec(Node* temp) {
        if (temp == NULL)
            return;

        printReverseRec(temp->next);
        cout << temp->data << " ";
    }

    int searchRec(Node* temp, int key, int pos) {
        if (temp == NULL)
            return -1;

        if (temp->data == key)
            return pos;

        return searchRec(temp->next, key, pos + 1);
    }

    void insertAtPosRec(Node* temp, int val, int pos, int current) {
        if (temp == NULL)
            return;

        if (current == pos - 1) {
            Node* newNode = new Node(val);

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newNode;

            temp->next = newNode;
            return;
        }

        insertAtPosRec(temp->next, val, pos, current + 1);
    }

    Node* deleteByValueRec(Node* temp, int val) {
        if (temp == NULL)
            return NULL;

        if (temp->data == val) {
            Node* nextNode = temp->next;

            if (nextNode != NULL)
                nextNode->prev = temp->prev;

            delete temp;
            return nextNode;
        }

        temp->next = deleteByValueRec(temp->next, val);

        if (temp->next != NULL)
            temp->next->prev = temp;

        return temp;
    }

    Node* deleteAtPosRec(Node* temp, int pos, int current) {
        if (temp == NULL)
            return NULL;

        if (current == pos) {
            Node* nextNode = temp->next;

            if (nextNode != NULL)
                nextNode->prev = temp->prev;

            delete temp;
            return nextNode;
        }

        temp->next = deleteAtPosRec(temp->next, pos, current + 1);

        if (temp->next != NULL)
            temp->next->prev = temp;

        return temp;
    }

    bool palindromeRec(Node*& left, Node* right) {
        if (right == NULL)
            return true;

        bool check = palindromeRec(left, right->next);

        if (!check)
            return false;

        bool same = (left->data == right->data);

        left = left->next;

        return same;
    }

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertBeginning(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    void insertEnd(int val) {
        head = insertEndRec(head, val);
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 1 || head == NULL) {
            insertBeginning(val);
            return;
        }

        insertAtPosRec(head, val, pos, 1);
    }

    void deleteByValue(int val) {
        head = deleteByValueRec(head, val);

        if (head != NULL)
            head->prev = NULL;
    }

    void deleteAtPosition(int pos) {
        if (pos < 1)
            return;

        head = deleteAtPosRec(head, pos, 1);

        if (head != NULL)
            head->prev = NULL;
    }

    int search(int key) {
        return searchRec(head, key, 1);
    }

    void printForward() {
        cout << "Forward: ";
        printForwardRec(head);
        cout << endl;
    }

    void printReverse() {
        cout << "Reverse: ";
        printReverseRec(head);
        cout << endl;
    }

    bool isPalindrome() {
        Node* left = head;
        return palindromeRec(left, head);
    }
};

int main() {
    DoublyLinkedList list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(1);

    list.printForward();
    list.printReverse();

    cout << "Position of 3: " << list.search(3) << endl;

    if (list.isPalindrome())
        cout << "List is Palindrome" << endl;
    else
        cout << "List is NOT Palindrome" << endl;

    list.insertBeginning(9);
    list.printForward();

    list.insertAtPosition(8, 3);
    list.printForward();

    list.deleteByValue(2);
    list.printForward();

    list.deleteAtPosition(2);
    list.printForward();

    return 0;
}