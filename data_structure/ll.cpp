#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

void printLL(Node *head)
{
    Node *tracker = head;

    while (tracker != nullptr)
    {
        cout << tracker->data << " ";
        tracker = tracker->next;
    }
}

void insertInHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertInTail(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        insertInHead(head, tail, data);
        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtAnyPos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertInHead(head, tail, data);
        return;
    }

    int count = 1;
    Node *tracker = head;
    while (count < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        count++;
    }

    if (tracker == nullptr)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (tracker->next == nullptr)
    {
        insertInTail(head, tail, data);
        return;
    }

    Node *temp = new Node(data);
    temp->next = tracker->next;
    tracker->next = temp;
}

void DeleteNode(Node *&head, Node *&tail, int pos)
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
    while (count < pos - 1 && tracker->next != nullptr)
    {
        tracker = tracker->next;
        count++;
    }

    if (tracker->next == nullptr || tracker == nullptr)
    {
        cout << "Invalid Delete Position";
        return;
    }

    Node *deleteNode = tracker->next;
    tracker->next = deleteNode->next;
    deleteNode->next = nullptr;

    delete deleteNode;

    if (tracker->next == nullptr)
    {
        tail = tracker;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertInTail(head, tail, 1);
    insertInTail(head, tail, 2);
    insertInTail(head, tail, 3);
    insertInTail(head, tail, 4);
    insertInTail(head, tail, 5);
    insertAtAnyPos(head, tail, 19, 6);
    cout << "Before delete: ";
    printLL(head);
    DeleteNode(head, tail, 90);
    cout << endl;
    cout << "After delete: ";
    printLL(head);
    cout << endl;
    cout << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;
    return 0;
}