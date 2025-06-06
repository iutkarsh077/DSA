#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void InsertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    if (head != nullptr) {
        head->prev = temp;
        temp->next = head;
    }
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    Node *temp = new Node(data);
    if (tail != nullptr) {
        temp->prev = tail;
        tail->next = temp;
    }
    tail = temp;
    if (head == nullptr) {
        head = temp;
    }
}


void deleteAtPos(Node *&head, Node *&tail, int pos) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node *curr = head;
    int cnt = 1;

    while (cnt < pos && curr != nullptr) {
        curr = curr->next;
        cnt++;
    }

    if (curr == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    if (curr->next == nullptr) {
        tail = curr->prev;
        tail->next = nullptr;
        delete curr;
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}


void print(Node *&head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtPos(Node *&head, Node *&tail, int pos, int data) {
    if (pos == 1) {
        InsertAtHead(head, data);
        return;
    }

    Node *curr = head;
    int cnt = 1;

    while (cnt < pos && curr != nullptr) {
        curr = curr->next;
        cnt++;
    }

    if (curr == nullptr) {
        insertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->prev = curr->prev;
    newNode->next = curr;

    if (curr->prev != nullptr) {
        curr->prev->next = newNode;
    }
    curr->prev = newNode;
}

int main() {
    Node *head = new Node(56);
    Node *tail = head;
    InsertAtHead(head, 55);
    InsertAtHead(head, 54);
    InsertAtHead(head, 53);
    insertAtTail(head, tail, 67);
    insertAtTail(head, tail, 4556);
    InsertAtPos(head, tail, 2, 991919191);
    deleteAtPos(head, tail, 7);
    print(head);
    return 0;
}
