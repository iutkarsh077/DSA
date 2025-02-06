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

Node *addNode(Node *head, int pos, int data)
{
    // code here
    int cnt = 0;
    Node *tracker = head;

    while (cnt < pos && tracker->next != nullptr)
    {
        cnt++;
        tracker = tracker->next;
    }

    Node *temp = new Node(data);
    temp->prev = tracker;
    temp->next = tracker->next;
    if (tracker->next != nullptr)
    {
        tracker->next->prev = temp;
    }
    tracker->next = temp;
    return head;
}

Node *deleteNode(Node *head, int x)
{
    // Your code here
    int cnt = 1;
    if (x == 1)
    {
        Node *targetNode = head;
        head->next->prev = nullptr;
        head = head->next;
        delete targetNode;
        return head;
    }

    Node *tracker = head;
    while (cnt < x && tracker != nullptr)
    {
        cnt++;
        tracker = tracker->next;
    }

    if (tracker == nullptr)
        return head;

    Node *targetNode = tracker;
    targetNode->prev->next = targetNode->next;
    if (targetNode->next != nullptr)
    {
        targetNode->next->prev = targetNode->prev;
    }
    delete targetNode;

    return head;
}

Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *forward = curr->next;

        curr->prev = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}

Node *constructDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int main2()
{
    return 0;
}


int main2()
{
    return 0;
}