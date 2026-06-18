#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int val;

    Node(int d)
    {
        this->val = d;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

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
    head->prev = temp;
    head = temp;
    return;
}

void printNode(Node *head){
    Node *temp = head;

    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = head;
    InsertAtHead(1, head);
    InsertAtHead(2, head);
    InsertAtHead(3, head);
    InsertAtHead(4, head);
    printNode(head);
    cout << "\n\n";
    cout << "Head is: " << head->val;
    cout << "Tail is: " << tail->val;

    return 0;
}