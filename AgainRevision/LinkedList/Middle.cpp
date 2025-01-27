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

bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != nullptr){
                fast = fast->next;
            }
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow;

        while(curr != nullptr){
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode *newHead = prev;
        ListNode *tracker = head;

        while(tracker != nullptr && newHead != nullptr){
            if(tracker->val != newHead->val){
                return false;
            }

            tracker = tracker->next;
            newHead = newHead->next;
        }

        return true;
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