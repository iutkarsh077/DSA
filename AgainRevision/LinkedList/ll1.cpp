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

void ArrayToLinkedListByHead(vector<int> arr, Node *head, Node *&tail)
{

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

Node *removesHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtAnyPlace(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;
    int cnt = 1;
    while (cnt < pos && curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr->next == nullptr)
    {
        Node *temp = new Node(data);
        curr->next = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    temp->next = curr;
    prev->next = temp;
    return;
}

int getCount(Node* head) {

        Node *temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        
        return cnt;
    }

void deleteNode(Node *node)
{
    Node *deleteNode = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete deleteNode;
}

int main()
{
    Node *head = new Node(-1);
    Node *tail = head;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ArrayToLinkedListByHead(arr, head, tail);
    head = removesHead(head);
    InsertAtHead(head, 0);
    InsertAtAnyPlace(head, tail, -1, 1);
    InsertAtAnyPlace(head, tail, 12, 12);
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