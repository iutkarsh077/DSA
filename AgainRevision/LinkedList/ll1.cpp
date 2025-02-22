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

class ListNode
{
public:
    int val;
    Node *next;

    Node(int data){
        this->val = data;
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

int getCount(Node *head)
{

    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

bool searchKey(int n, Node *head, int key)
{
    // Code here
    Node *temp = head;

    while (temp != nullptr)
    {
        if (key == temp->data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool searchKey2(int n, Node *head, int key)
{
    // Code here
    Node *temp = head;

    while (temp != nullptr)
    {
        if (key == temp->data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1->val == 0 && l2->val == 0)
    {
        return new ListNode(0);
    }
    long long int sum1 = 0;
    long long int sum2 = 0;

    ListNode *tracker = l1;
    ListNode *tracker2 = l2;

    while (tracker != nullptr || tracker2 != nullptr)
    {
        if (tracker != nullptr)
        {
            int val = tracker->val;
            sum1 = (sum1 * 10) + val;
            tracker = tracker->next;
        }

        if (tracker2 != nullptr)
        {
            int val = tracker2->val;
            sum2 = (sum2 * 10) + val;
            tracker2 = tracker2->next;
        }
    }

    long long int total = sum1 + sum2;

    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    while (total > 0)
    {
        int digit = total % 10;
        ListNode *temp = new ListNode(digit);
        tail->next = temp;
        tail = temp;
        total = total / 10;
    }

    ListNode *deleteNode = head;
    head = head->next;
    delete deleteNode;
    return head;
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