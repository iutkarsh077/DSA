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
    PrintNode(head);
    return 0;
}
