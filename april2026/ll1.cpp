#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

void PrintNode(Node *head)
{
    Node *tracker = head;

    while (tracker != nullptr)
    {
        cout << tracker->val << " ";
        tracker = tracker->next;
    }
}

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
    head = temp;
}

void InsertAtTail(int data, Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtAnyPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (head == nullptr || pos == 1)
    {
        InsertAtHead(data, head);
        return;
    }

    Node *tracker = head;
    int count = 1;
    while (count < pos - 1 && tracker != nullptr)
    {
        tracker = tracker->next;
        count++;
    }

    if (tracker == nullptr || tracker->next == nullptr)
    {
        InsertAtTail(data, head, tail);
        return;
    }

    Node *temp = new Node(data);
    temp->next = tracker->next;
    tracker->next = temp;
    return;
}

int LengthofLL(Node *head)
{
    Node *tracker = head;
    int count = 1;
    while (tracker != nullptr)
    {
        tracker = tracker->next;
        count = count + 1;
    }
}

Node *removeNthFromEnd(Node *head, int n)
{
    int len = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    int nFront = len - n;

    if (nFront == 0)
    {
        Node *deleteNode = head;
        head = head->next;

        deleteNode->next = nullptr;
        delete deleteNode;
        return head;
    }

    temp = head;

    int cnt = 0;
    while (cnt < nFront - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    deleteNode->next = nullptr;

    delete deleteNode;

    return head;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    int num1 = 0;
    int num2 = 0;

    while (l1 != nullptr)
    {
        int val = l1->val;
        num1 = (num1 * 10) + val;
        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        int val = l2->val;
        num2 = (num2 * 10) + val;
        l2 = l2->next;
    }

    long long result = num1 + num2;

    Node *head = new Node(-1);
    Node *tail = head;

    if (result == 0)
    {
        return new Node(0);
    }

    while (result != 0)
    {
        int val = result % 10;
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
        result = result / 10;
    }
    return head->next;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *firstHead = new Node(-1);
    Node *firstTail = firstHead;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            Node *data = new Node(list1->val);
            firstTail->next = data;
            firstTail = data;
            list1 = list1->next;
        }
        else
        {
            Node *data = new Node(list2->val);
            firstTail->next = data;
            firstTail = data;
            list2 = list2->next;
        }
    }

    while (list1 != nullptr)
    {
        Node *data = new Node(list1->val);
        firstTail->next = data;
        firstTail = data;
        list1 = list1->next;
    }

    while (list2 != nullptr)
    {
        Node *data = new Node(list2->val);
        firstTail->next = data;
        firstTail = data;
        list2 = list2->next;
    }

    firstHead = firstHead->next;

    return firstHead;
}

bool hasCycle(Node *head)
{
    unordered_map<Node *, int> mp;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end())
        {
            return true;
        }

        mp[temp] = temp->val;
        temp = temp->next;
    }

    return false;
}

Node *ReverseNode(Node *head, int k)
{
    Node *prev = nullptr;
    Node *curr = head;
    int cnt = 0;

    while (curr != nullptr && cnt < k)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }

    Node *curr = slow;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    Node *first = head;
    Node *second = prev;

    while (first != nullptr && second != nullptr)
    {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    bool isCircle = false;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return nullptr;
}

Node *rotateRight(Node *head, int k)
{
    vector<int> arr;

    Node *temp = head;

    while (temp != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    if (arr.size() == 0)
        return nullptr;

    k = k % arr.size();

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());

    Node *newHead = new Node(arr[0]);
    Node *newtail = newHead;

    if (arr.size() == 1)
        return newHead;
    int i = 1;
    while (i < arr.size())
    {
        Node *node = new Node(arr[i]);
        newtail->next = node;
        newtail = node;
        i++;
    }

    return newHead;
}

Node *reverseKGroup(Node *head, int k)
{
    if (head == nullptr || k == 1)
        return head;

    int len = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    Node *dummy = new Node(-1);
    Node *dummyTail = dummy;

    temp = head;

    while (len >= k)
    {

        Node *nextGroup = temp;
        for (int i = 0; i < k; i++)
            nextGroup = nextGroup->next;

        Node *newHead = ReverseNode(temp, k);

        dummyTail->next = newHead;

        dummyTail = temp;

        temp = nextGroup;

        len -= k;
    }

    dummyTail->next = temp;

    return dummy->next;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    int len1 = 0;
    int len2 = 0;

    Node *temp1 = headA;
    Node *temp2 = headB;

    while (temp1 != nullptr)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr)
    {
        len2++;
        temp2 = temp2->next;
    }

    temp1 = headA;
    temp2 = headB;

    if (len1 > len2)
    {
        int footsteps = len1 - len2;

        while (footsteps > 0)
        {
            temp1 = temp1->next;
            footsteps--;
        }
    }
    else
    {
        int footsteps = len2 - len1;

        while (footsteps > 0)
        {
            temp2 = temp2->next;
            footsteps--;
        }
    }

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return nullptr;
}

void deleteNode(Node *node)
{
    Node *deleteMe = node->next;
    node->val = node->next->val;
    node->next = node->next->next;

    deleteMe->next = nullptr;

    delete deleteMe;
}

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void deleteNode1(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        return;
    }

    Node *tracker = head;
    int count = 1;

    while (tracker != nullptr && count < pos - 1)
    {
        tracker = tracker->next;
        count++;
    }

    if (tracker->next == nullptr)
    {
        cout << "The Length of Linked list is smaller then your position";
        return;
    }

    if (tracker->next->next == nullptr)
    {
        Node *deleteNode = tail;
        tail = tracker;
        tail->next = nullptr;
        delete deleteNode;
        return;
    }

    Node *deleteNode = tracker->next;
    tracker->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
    return;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    // InsertAtHead(5, head);
    // InsertAtHead(4, head);
    // InsertAtHead(3, head);
    // InsertAtHead(2, head);
    // InsertAtHead(1, head);

    InsertAtTail(1, head, tail);
    InsertAtTail(2, head, tail);
    InsertAtTail(3, head, tail);
    InsertAtTail(4, head, tail);
    InsertAtTail(5, head, tail);
    insertAtAnyPosition(head, tail, 78, 2);
    deleteNode1(head, tail, 7);
    PrintNode(head);
    return 0;
}
