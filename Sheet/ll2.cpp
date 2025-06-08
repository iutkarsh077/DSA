#include<iostream>
using namespace std;

 void deleteNode(ListNode* node) {
        ListNode *deleteNode = node->next;
        node->val = node->next->val;
        node->next = deleteNode->next;
        deleteNode->next = nullptr;
        delete deleteNode;
    }

int main(){
    return 0;
}