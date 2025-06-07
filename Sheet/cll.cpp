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

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data){
    Node *temp = new Node(data);
    if(head == nullptr){
        head = temp;
        tail = temp;
        temp->next = temp;
    }
    else{
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}


void InsertAtAnyPos(Node *&head, Node *&tail, int data, int pos){
    Node *temp = new Node(data);
    if(head == nullptr){
        head = temp;
        tail = temp;
        temp->next = temp;
        return;
    }

    if(pos == 1){
        InsertAtHead(head, tail, data);
        return;
    }

    Node *tracker = head;
    int cnt = 1;
   while (cnt < pos - 1 && tracker->next != head) {
        tracker = tracker->next;
        cnt++;
    }


    if(tracker->next == head){
        InsertAtTail(head, tail, data);
        return;
    }

    temp->next = tracker->next;
    tracker->next = temp;
}

void print(Node *head)
{
    Node *temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    InsertAtTail(head, tail, 10);
    InsertAtTail(head, tail, 9);
    InsertAtTail(head, tail, 8);
    InsertAtTail(head, tail, 7);
    InsertAtTail(head, tail, 6);
    InsertAtTail(head, tail, 5);
    InsertAtTail(head, tail, 4);
    InsertAtAnyPos(head, tail, 687, 9);
    print(head);
    return 0;
}