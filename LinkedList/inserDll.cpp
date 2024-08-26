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


void addNode(Node *head, int pos, int data)
{
   // Your code here
   if(pos == 0){
       Node *temp = new Node(data);
       temp->next = head;
       head->prev = temp;
       head = temp;
       return;
   }
   
    Node *temp = head;
    int cnt = 0;
    while(temp->next != nullptr && cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }
    
    if(temp->next == nullptr){
        Node *newNode = new Node(data);
        newNode->prev = temp;
        temp->next = newNode;
        return;
    }
    
    Node *newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
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


int main() {

    int arr[] = {2, 4, 5};
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for(int i = 1; i < 3; i++){
        Node *temp = new Node(arr[i]);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    addNode(head, 2, 6);

    printNode(head);
    return 0;
}