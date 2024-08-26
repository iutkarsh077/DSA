#include <bits/stdc++.h>
#include <iostream>
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

void InsertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printNode(Node *head)
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
        InsertAtHead(data, head);
        return;
    }

    else
    {
        int cnt = 1;
        Node *temp = head;
        while (temp->next != nullptr && cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp == nullptr)
        {
            Node *newNode = new Node(data);
            temp->next = newNode;
            tail = newNode;
            return;
        }

        Node *myNode = new Node(data);
        myNode->next = temp->next;
        temp->next = myNode;
    }
}

void DeleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        delete head;
        if (head == nullptr)
        {
            tail == nullptr;
        }
        return;
    }

    else
    {
        Node *curr = head;
        Node *prev = nullptr;
        int cnt = 1;
        while (cnt <= pos - 1)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == nullptr)
        {
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}

int main()
{
    Node *head = new Node(15);
    Node *tail = head;
    InsertAtHead(14, head);
    InsertAtTail(tail, 16);
    InsertAtTail(tail, 17);
    InsertAtMiddle(head, tail, 12, 2);
    DeleteNode(head, tail, 2);
    printNode(head);
    return 0;
}