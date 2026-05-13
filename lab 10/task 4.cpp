#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void printList(Node* head) {
    if (head == NULL)
        return;
    cout << head->data << " ";
    printList(head->next);
}
int main() {
    Node* first = new Node{ 10, NULL };
    Node* second = new Node{ 20, NULL };
    Node* third = new Node{ 30, NULL };
    first->next = second;
    second->next = third;
    printList(first);
    return 0;
}