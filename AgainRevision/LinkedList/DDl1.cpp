#include <bits/stdc++.h>
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

class ListNode
{
public:
    int data;
    Node *prev;
    Node *next;

    ListNode(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }


    

    void hello(){
        cout << "Hello World";
    }
};



class Solution {
    public:
      void deleteAllOccurOfX(struct Node** head_ref, int x) {
      if (*head_ref == nullptr) {
          return;
      }
  
      Node* current = *head_ref;
  
      // Handle the case where the head node(s) need to be deleted
      while (current != nullptr && current->data == x) {
          Node* deleteNode = current;
          current = current->next;
          if (current != nullptr) {
              current->prev = nullptr;
          }
          *head_ref = current;
          delete deleteNode;
      }
  
      // If the list becomes empty after deleting the head nodes
      if (current == nullptr) {
          return;
      }
  
      // Now handle the remaining nodes
      while (current != nullptr) {
          if (current->data == x) {
              Node* deleteNode = current;
              Node* prevNode = deleteNode->prev;
              Node* nextNode = deleteNode->next;
  
              if (prevNode != nullptr) {
                  prevNode->next = nextNode;
              }
  
              if (nextNode != nullptr) {
                  nextNode->prev = prevNode;
              }
  
              current = nextNode;
  
              delete deleteNode;
          } else {
              current = current->next;
          }
      }
  }
  
  };

void InsertNode(Node *head, Node *&tail, vector<int> nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        Node *myNode = new Node(nums[i]);
        myNode->prev = tail;
        tail->next = myNode;
        tail = myNode;
    }
}

void printLinkedList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtAnyPlace(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        if (tail == nullptr)
            tail = head;
        return;
    }

    int cnt = 1;
    Node *temp = head;

    while (cnt < pos - 1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds. Node appended at the end.\n";
        Node *newNode = new Node(data);
        if (tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void DeleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }

    Node *tracker = head;
    int cnt = 1;
    while (cnt < pos && tracker != nullptr)
    {
        cnt++;
        tracker = tracker->next;
    }

    if (tracker == nullptr)
    {
        cout << "Position out of bounds. Node deleted at the end.\n";
        return;
    }

    if (tracker->next == nullptr)
    {
        tracker->prev->next = nullptr;
        tail = tracker->prev;
        delete tracker;
        return;
    }

    tracker->prev->next = tracker->next;
    tracker->next->prev = tracker->prev;
    delete tracker;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(nums[0]);
    Node *tail = head;

    InsertNode(head, tail, nums);
    InsertAtHead(head, 0);
    // InsertAtAnyPlace(head, tail, 7, 89);
    DeleteNode(head, tail, 8);
    printLinkedList(head);
}