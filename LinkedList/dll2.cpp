#include <bits/stdc++.h>
#include <iostream>
#include <string>
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
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    return;
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

void InsertAtMiddle(Node *&head, Node *&tail, int data, int pos){
    if(pos == 1){
        InsertAtHead(head, data);
        return;
    }

    else{
        Node *temp = head;
        int cnt = 1;
        while(cnt < pos - 1 && temp->next != nullptr){
            temp = temp->next;
            cnt++;
        }

        if(temp->next == nullptr){
            InsertAtTail(tail, data);
            return;
        }

        Node *newNode = new Node(data);
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }   
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
        while(cnt < position && curr->next != nullptr) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr->next == nullptr){
            return;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}


int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    InsertAtHead(head, 9);
    InsertAtHead(head, 8);
    InsertAtHead(head, 7);
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    // InsertAtHead(head, 3);
    deleteNode(8, head);
    // InsertAtTail(tail, 1123);
    // InsertAtMiddle(head, tail, 2, 1);
    printNode(head);
    cout << endl;
    cout << "The head is: " << head->data << endl;
    cout << "The tail is: " << tail->data << endl;
    return 0;
}