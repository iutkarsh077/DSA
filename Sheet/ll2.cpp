#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

void deleteNode(ListNode *node)
{
    ListNode *deleteNode = node->next;
    node->val = node->next->val;
    node->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
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

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *dupHead = new ListNode(head->val);
    ListNode *tracker = head->next;
    while (tracker != nullptr)
    {
        ListNode *newHead = new ListNode(tracker->val);
        newHead->next = dupHead;
        dupHead = newHead;
        tracker = tracker->next;
    }

    return dupHead;
}

void custom(ListNode *tracker, ListNode *&dupHead)
{
    if (tracker == nullptr)
        return;

    ListNode *newHead = new ListNode(tracker->val);
    newHead->next = dupHead;
    dupHead = newHead;
    tracker = tracker->next;

    custom(tracker, dupHead);
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *dupHead = new ListNode(head->val);
    ListNode *tracker = head->next;
    custom(tracker, dupHead);

    return dupHead;
}

int main()
{
    return 0;
}