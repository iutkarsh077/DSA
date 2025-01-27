#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

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

int main()
{
    
    return 0;
}