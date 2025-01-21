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

int main()
{
    return 0;
}