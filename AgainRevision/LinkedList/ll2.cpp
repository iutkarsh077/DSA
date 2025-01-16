#include <bits/stdc++.h>
#include <iostream>
#include <string>
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

void LinkedToArray(Node *&head, vector<int> arr)
{
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
}
Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    LinkedToArray(head, arr);
    return head;
}

int main()
{
    return 0;
}