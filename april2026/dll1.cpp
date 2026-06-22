#include <iostream>
#include <bits/stdc++.h>
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

void printNode(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void deleteHead(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    head->prev = nullptr;
    deleteNode->next = nullptr;
    delete deleteNode;
}

void reverseLL(Node *&head, Node *&tail)
{
    Node *curr = head;
    Node *prev = nullptr;
    tail = head;
    while (curr != nullptr)
    {
        Node *forward = curr->next;
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

int getLength(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
Node *getIntersectionNode(Node *headA, Node *headB)
{
    int first = getLength(headA);
    int second = getLength(headB);

    Node *firstNode = headA;
    Node *secondNode = headB;
    if (first > second)
    {
        int remaining = first - second;
        while (remaining > 0)
        {
            firstNode = firstNode->next;
            remaining--;
        }
    }
    else
    {
        int remaining = second - first;
        while (remaining > 0)
        {
            secondNode = secondNode->next;
            remaining--;
        }
    }

    while (firstNode != nullptr && secondNode != nullptr)
    {
        if (firstNode == secondNode)
        {
            return firstNode;
        }
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }

    return nullptr;
}

Node *sortList(Node *head)
{
    vector<int> nums;
    Node *temp = head;

    while (temp != nullptr)
    {
        nums.push_back(temp->val);
        temp = temp->next;
    }

    sort(nums.begin(), nums.end());
    if (nums.size() == 0)
        return nullptr;
    Node *hello = new Node(nums[0]);
    Node *tail = hello;

    int i = 1;
    while (i < nums.size())
    {
        Node *second = new Node(nums[i]);
        tail->next = second;
        tail = second;
        i++;
    }

    return hello;
}

int main()
{
    Node *head = nullptr;
    Node *tail = head;
    InsertAtHead(1, head);
    InsertAtHead(2, head);
    InsertAtHead(3, head);
    InsertAtHead(4, head);
    // deleteHead(head);
    reverseLL(head, tail);
    printNode(head);
    cout << "\n\n";
    cout << "Head is: " << head->val;
    cout << "Tail is: " << tail->val;

    return 0;
}