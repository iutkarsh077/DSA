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

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = head;
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void InsertAtMiddle(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        if (head == nullptr)
        {
            InsertAtHead(head, tail, data);
            return;
        }
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    int cnt = 1;
    Node *tracker = head;

    while (cnt < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        cnt = cnt + 1;
    }

    Node *temp = new Node(data);
    if (tracker == nullptr || tracker->next == nullptr)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        return;
    }

    temp->prev = tracker;
    temp->next = tracker->next;
    tracker->next->prev = temp;
    tracker->next = temp;
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

void DeleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *deleteNode = head;
        head = head->next;
        head->prev = nullptr;
        deleteNode->next = nullptr;
        delete deleteNode;
        return;
    }

    int cnt = 1;
    Node *tracker = head;
    while (cnt < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        cnt = cnt + 1;
    }

    if (tracker == nullptr || tracker->next == nullptr)
    {
        cout << "Position Out of Bound" << endl;
        return;
    }

    if (tracker->next == tail)
    {
        Node *deleteNode = tail;
        tail = tracker;
        tracker->next = nullptr;
        deleteNode->prev = nullptr;
        delete deleteNode;
        return;
    }

    Node *deleteNode = tracker->next;
    deleteNode->next->prev = tracker;
    tracker->next = deleteNode->next;
    deleteNode->prev = nullptr;
    deleteNode->prev = nullptr;
    return;
}

void ReverseDLL(Node *&head, Node *&tail)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *curr = head;
    Node *temp = nullptr;

    while (curr != nullptr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    tail = head;
    if (temp != nullptr)
        head = temp->prev;
}

Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }

    return slow;
}

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool hasCycle(Node *head) {
        Node *slow = head;
        Node *fast = head;

        if(slow == nullptr || slow->next == nullptr) return false;

        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;

            if(fast != nullptr){
                fast = fast->next;
            }

            if(slow == fast) return true;
        }

        return false;
    }

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 4);
    InsertAtHead(head, tail, 3);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    // InsertAtTail(head, tail, 1);
    // InsertAtTail(head, tail, 2);
    // InsertAtTail(head, tail, 3);
    // InsertAtTail(head, tail, 4);
    // InsertAtTail(head, tail, 5);
    // InsertAtTail(head, tail, 6);
    // InsertAtMiddle(head, tail, 0, 1);
    // InsertAtMiddle(head, tail, 18, 10897897);
    // DeleteNode(head, tail, 9);
    ReverseDLL(head, tail);
    printNode(head);
    cout << endl
         << "The head is: " << head->data << endl;
    cout << "The tail is: " << tail->data << endl;
    return 0;
}