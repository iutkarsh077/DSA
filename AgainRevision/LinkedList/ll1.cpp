#include <bits/stdc++.h>
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

void ArrayToLinkedListByHead(vector<int> arr, Node *head)
{
    Node *tail = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
}

void PrintList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(-1);
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ArrayToLinkedListByHead(arr, head);
    PrintList(head);
    return 0;
}

int val()
{
    int a = 9;
    int *b = &a;
    cout << &a << endl;
    cout << b << endl;
    cout << &b;
    return 0;
}