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
        this->next = nullptr;
    }
};

void insertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(int data, Node *&head, Node *&tail)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(int data, int pos, Node *&head, Node *&tail)
{
    Node *tracker = head;
    int cnt = 1;

    if (pos == 1)
    {
        insertAtHead(data, head);
        if (tail == nullptr)
            tail = head;
        return;
    }
    while (cnt < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        cnt++;
    }

    Node *temp = new Node(data);
    if (tracker == nullptr)
    {
        tail->next = temp;
        tail = temp;
        return;
    }
    temp->next = tracker->next;
    tracker->next = temp;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(int data, int pos, Node *&head, Node *&tail)
{
    if (pos == 1)
    {
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }

    int cnt = 1;
    int size = 0;
    Node *tracker = head;

    while (tracker != nullptr)
    {
        tracker = tracker->next;
        size++;
    }

    tracker = head;

    if (pos > size)
    {
        cout << "deleting element is out of bound" << endl;
        return;
    }

    while (cnt < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        cnt++;
    }

    if (tracker == nullptr)
    {
        cout << "deleting element is out of bound" << endl;
        return;
    }

    Node *deleteElement = tracker->next;
    if(deleteElement->next == nullptr){
        tail = tracker;
    }
    tracker->next = tracker->next->next;

    delete deleteElement;
}

int main2()
{
    Node *head = nullptr;
    Node *tail = head;
    insertAtTail(1, head, tail);
    insertAtTail(2, head, tail);
    insertAtTail(3, head, tail);
    insertAtTail(4, head, tail);
    insertAtTail(5, head, tail);
    insertAtTail(6, head, tail);
    insertAtMiddle(18, 868767, head, tail);
    deleteNode(1, 5, head, tail);
    printLinkedList(head);
    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;
    return 0;
}

class DoublyEndedNode{
    public:
    int data;
    DoublyEndedNode *prev;
    DoublyEndedNode *next;

    DoublyEndedNode(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


int main(){
    
}