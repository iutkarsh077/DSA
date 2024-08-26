#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void printNode(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}


void InsertAtMiddle(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp->next != nullptr)
    {
        temp = temp->next;
        cnt = cnt + 1;
    }

    if(temp->next == nullptr || temp == nullptr){
        InsertAtTail(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    temp->next  = newNode;
}


void deleteNode(int position, Node* & head) { 

    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}



int main()
{
    Node *node1 = new Node(50);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 40);
    InsertAtHead(head, 30);
    InsertAtTail(tail, 60);
    InsertAtTail(tail, 70);
    InsertAtMiddle(head, tail, 35, 7);
    printNode(head);
    cout << endl
         << head->data << "  " << tail->data;
    return 0;
}