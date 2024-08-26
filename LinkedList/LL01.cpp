#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int data)
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

void InsertAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void DeleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
        return;
    }

    else{
        Node *curr = head;
        Node *prev = nullptr;

        int cnt = 1;
        while(cnt <= pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == nullptr){
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}


void InsertAtMiddle(int pos, int data, Node *&head, Node *&tail)
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
    if (temp->next == nullptr)
    {
        InsertAtTail(data, tail);
        return;
    }
    Node *myNode = new Node(data);
    myNode->next = temp->next;
    temp->next = myNode;
}

int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    InsertAtTail(20, tail);
    InsertAtTail(30, tail);
    InsertAtTail(40, tail);
    InsertAtMiddle(3, 25, head, tail);
    InsertAtMiddle(1, 5, head, tail);
    InsertAtMiddle(7, 50, head, tail);
    InsertAtMiddle(9, 60, head, tail);
    InsertAtMiddle(4, 32, head, tail);
    DeleteNode(head, tail, 8);

    printNode(head);
    cout << endl
         << head->data << " " << tail->data;
    return 0;
}