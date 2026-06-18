#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

void PrintNode(Node *head)
{
    Node *tracker = head;

    while (tracker != nullptr)
    {
        cout << tracker->val << " ";
        tracker = tracker->next;
    }
}

void InsertAtHead(int data, Node *&head)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(int data, Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtAnyPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (head == nullptr || pos == 1)
    {
        InsertAtHead(data, head);
        return;
    }

    Node *tracker = head;
    int count = 1;
    while (count < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        count++;
    }

    if (tracker == nullptr || tracker->next == nullptr)
    {
        InsertAtTail(data, head, tail);
        return;
    }

    Node *temp = new Node(data);
    temp->next = tracker->next;
    tracker->next = temp;
    return;
}

int LengthofLL(Node *head)
{
    Node *tracker = head;
    int count = 1;
    while (tracker != nullptr)
    {
        tracker = tracker->next;
        count = count + 1;
    }
}

void deleteNode1(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        return;
    }


    Node *tracker = head;
    int count = 1;

    while (tracker != nullptr && count < pos - 1)
    {
        tracker = tracker->next;
        count++;
    }

    if(tracker->next == nullptr){
        cout << "The Length of Linked list is smaller then your position";
        return;
    }

    if (tracker->next->next == nullptr)
    {
        Node *deleteNode = tail;
        tail = tracker;
        tail->next = nullptr;
        delete deleteNode;
        return;
    }

    Node *deleteNode = tracker->next;
    tracker->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
    return;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    // InsertAtHead(5, head);
    // InsertAtHead(4, head);
    // InsertAtHead(3, head);
    // InsertAtHead(2, head);
    // InsertAtHead(1, head);

    InsertAtTail(1, head, tail);
    InsertAtTail(2, head, tail);
    InsertAtTail(3, head, tail);
    InsertAtTail(4, head, tail);
    InsertAtTail(5, head, tail);
    insertAtAnyPosition(head, tail, 78, 2);
    deleteNode1(head, tail, 7);
    PrintNode(head);
    return 0;
}
