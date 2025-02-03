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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void Lalala(ListNode *&prev, ListNode *curr)
{
    if (curr == nullptr)
        return;

    ListNode *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    Lalala(prev, curr);
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

ListNode *reverseList2(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;
    Lalala(prev, curr);
    return prev;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }

    return slow;
}

ListNode *HeadOfLoop(ListNode *head)
{
    ListNode *temp = head;
    map<ListNode *, int> mpp;

    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }

        mpp[temp] = 1;
        temp = temp->next;
    }
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }

    ListNode *prev = nullptr;
    ListNode *curr = slow;

    while (curr != nullptr)
    {
        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    ListNode *newHead = prev;
    ListNode *tracker = head;

    while (tracker != nullptr && newHead != nullptr)
    {
        if (tracker->val != newHead->val)
        {
            return false;
        }

        tracker = tracker->next;
        newHead = newHead->next;
    }

    return true;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *tracker = head;

    while (tracker != nullptr)
    {
        len++;
        tracker = tracker->next;
    }

    int deleteNodeIndex = len - n;

    if (deleteNodeIndex == 0)
    {
        ListNode *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        return head;
    }

    tracker = head;
    int cnt = 0;

    while (cnt < deleteNodeIndex - 1 && tracker != nullptr)
    {
        cnt++;
        tracker = tracker->next;
    }

    if (tracker == nullptr)
    {
        return head;
    }

    ListNode *deleteNode = tracker->next;
    tracker->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
    return head;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> arr;
    ListNode *tracker = head;

    while (tracker != nullptr)
    {
        arr.push_back(tracker->val);
        tracker = tracker->next;
    }

    sort(arr.begin(), arr.end());

    tracker = head;

    for (int i = 0; i < arr.size(); i++)
    {
        tracker->val = arr[i];
        tracker = tracker->next;
    }

    return head;
}

Node *segregate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;

    Node *tracker = head;

    while (tracker != nullptr)
    {
        if (tracker->data == 0)
        {
            zeroCnt++;
        }

        else if (tracker->data == 1)
        {
            oneCnt++;
        }

        else
        {
            twoCnt++;
        }

        tracker = tracker->next;
    }

    tracker = head;
    while (tracker != nullptr)
    {
        if (zeroCnt > 0)
        {
            tracker->data = 0;
            zeroCnt--;
        }

        else if (oneCnt > 0)
        {
            tracker->data = 1;
            oneCnt--;
        }

        else
        {
            tracker->data = 2;
            twoCnt--;
        }

        tracker = tracker->next;
    }

    return head;
}

ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->next == nullptr)
    {
        return nullptr;
    }

    ListNode *slowPrev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    slowPrev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
}

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *oddHead = head, *oddTail = head;
    ListNode *evenHead = head->next, *evenTail = head->next;

    ListNode *tracker = evenTail->next;
    int index = 3;

    while (tracker)
    {
        if (index % 2 == 1)
        {
            oddTail->next = tracker;
            oddTail = tracker;
        }
        else
        {
            evenTail->next = tracker;
            evenTail = tracker;
        }
        tracker = tracker->next;
        index++;
    }

    evenTail->next = nullptr;
    oddTail->next = evenHead;
    return oddHead;
}

int countNodesinLoop(struct ListNode *head)
{
    // Code here
    ListNode *slow = head;
    ListNode *fast = head;

    ListNode *begin = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast == nullptr || fast->next == nullptr)
        {
            return 0;
        }

        if (fast->next != nullptr)
        {
            fast = fast->next;
        }

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            begin = slow;
            break;
        }
    }

    if (begin == nullptr)
    {
        return 0;
    }

    ListNode *track = begin->next;
    int cnt = 0;

    while (track != begin)
    {
        cnt++;
        track = track->next;
    }

    if (cnt == 0)
        return 0;

    return cnt + 1;
}

int main()
{

    return 0;
}