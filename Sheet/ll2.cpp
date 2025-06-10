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

 bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }

     bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != nullptr){
                fast = fast->next;
            }
        }

        ListNode *curr = slow;
        ListNode *prev = nullptr;
        while(curr != nullptr){
           ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;  
        }

        ListNode *temp = head;
        ListNode *newHead = prev;
        while(newHead != nullptr && temp != nullptr){
            if(newHead->val !=  temp->val){
                return false;
            }
            newHead = newHead->next;
            temp = temp->next;
        }

        return true;
    }

     ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *oddNodeHead = new ListNode(-1);
        ListNode *oddNodeTail = oddNodeHead;
        ListNode *evenNodeHead = new ListNode(-1);
        ListNode *evenNodeTail = evenNodeHead;
        ListNode *tracker = head;
        int index = 1;

        while(tracker != nullptr){
            int val = tracker->val;
            if(index % 2 == 0){
                ListNode *newNode = new ListNode(val);
                evenNodeTail->next = newNode;
                evenNodeTail = newNode;
            }
            else{
                 ListNode *newNode = new ListNode(val);
                oddNodeTail->next = newNode;
                oddNodeTail = newNode;
            }
            tracker = tracker->next;
            index = index + 1;
        }

        ListNode *deleteEvenHead = evenNodeHead;
        evenNodeHead = evenNodeHead->next;
        ListNode *deleteOddHead = oddNodeHead;
        oddNodeHead = oddNodeHead->next;
        delete deleteEvenHead;
        delete deleteOddHead;
        oddNodeTail->next = evenNodeHead;
        return oddNodeHead;
    }

int main()
{
    return 0;
}