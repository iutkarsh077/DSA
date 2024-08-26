#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void PrintNode(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void InsertAtMiddle(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }

    else
    {
        int cnt = 1;
        Node *temp = head;

        while (cnt < pos - 1 && temp->next != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            InsertAtTail(tail, data);
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void DeleteNode(Node *&head, Node *&tail, int pos) {
    // Case: Deleting the head node
    if (pos == 1) {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        // Update the tail if the list becomes empty
        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }

    // General case
    Node *curr = head;
    Node *prev = nullptr;
    int cnt = 1;
    while (cnt < pos && curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr != nullptr) {
        prev->next = curr->next;
        if (curr->next == nullptr) {
            tail = prev;
        }
        delete curr;
    }
}


int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    InsertAtHead(head, 9);
    InsertAtHead(head, 8);
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 14);
    InsertAtMiddle(head, tail, 13, 9);
    cout << endl;
    DeleteNode(head, tail, 6);
    PrintNode(head);
    cout << endl;
    cout << "The head is: " << head->data << " and the address is " << head << endl;
    cout << "The tail is: " << tail->data << " and the address is " << tail;

    return 0;
}