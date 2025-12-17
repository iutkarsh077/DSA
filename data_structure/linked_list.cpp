#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next = nullptr;
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
};


void insertAtHead(int data, Node *&head){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(int data, Node *&tail){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void printNode(Node *head){
    Node *temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteElement(int pos, Node *&head, Node *&tail){
    if(pos == 1){
        Node *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        return;
    }

    int cnt = 1;
    Node *tracker = head;
    while(cnt < pos - 1 && tracker != nullptr){
        tracker = tracker->next;
        cnt++;
    }

    if(tracker == nullptr || tracker->next == nullptr){
        cout << "Position is not valid" << endl;
        return;
    }

    if(tracker->next->next == nullptr){
        Node *deleteNode = tracker->next;
        tail = tracker;
        tracker->next = nullptr;
        delete deleteNode;
        return;
    }

    Node *deleteNode = tracker->next;
    tracker->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

void mystl(){
    list<int> names;

    names.push_back(1);
    names.push_back(2);
    names.push_back(3);

    cout << names.empty() << endl;

    for(auto i = names.begin(); i != names.end(); i++){
        cout << *i << endl;
    }
}


int main(){
    // Node *head = new Node(0);
    // Node *tail = head;
    // insertAtHead(4, head);
    // insertAtHead(3, head);
    // insertAtHead(2, head);
    // insertAtHead(1, head);
    // insertAtTail(1, tail);
    // insertAtTail(2, tail);
    // insertAtTail(3, tail);
    // insertAtTail(4, tail);
    // insertAtTail(5, tail);
    // deleteElement(7, head, tail);
    // cout << endl << endl;
    // cout << head->data << endl;
    // cout << tail->data << endl;
    // printNode(head);
    mystl();
    return 0;
}