#include<iostream>
using namespace std;

class Nodes{
    public:
    int data;
    Nodes *next;

    Nodes(int d){
        this->data = d;
        this->next = nullptr;
    }
};

void InsertAtHead(Nodes *&head, int data){
    Nodes *temp = new Nodes(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Nodes *&tail, int data){
    Nodes *temp = new Nodes(data);
    tail->next = temp;
    tail = temp;
}


void InsertAtMiddle(Nodes *&head, Nodes *&tail, int pos, int data){
    if(pos == 1){
        InsertAtHead(head, data);
        return;
    }

    Nodes *curr = head;
    Nodes *prev = nullptr;
    Nodes *forward = nullptr;
    int cnt = 1;

    while(cnt < pos - 1 && curr != nullptr){
        forward = curr->next;
        prev = curr;
        curr = curr->next;
        cnt = cnt + 1;
    }

    if(curr == nullptr || curr->next == nullptr){
        InsertAtTail(tail, data);
        return;
    }

    Nodes *temp = new Nodes(data);
    temp->next = curr->next;
    curr->next = temp;
}

void DeleteNode(int pos, Nodes *&head, Nodes *&tail){
    if(pos == 1) {
        Nodes *temp = head;
        head = head->next;
        delete temp;
    }
    else{
        Nodes *curr = head;
        Nodes *prev = nullptr;
        int cnt = 1;

        while(cnt < pos && curr != nullptr){
            prev = curr;
            curr = curr->next;
            cnt = cnt + 1;
        }
        if(cnt < pos){
            cout << "This position is not available, List is smaller then this" << endl;
            return;
        }

        prev->next = curr->next;
        if(curr->next == nullptr){
            tail = prev;
        }
        curr->next = nullptr;
        delete curr;
    }
}

void printLinkedList(Nodes *head){
    Nodes *temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Nodes *head = new Nodes(10);
    Nodes *tail = head;
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 6);
    InsertAtMiddle(head, tail, 12, 23);
    DeleteNode(10, head, tail);
    printLinkedList(head);
    return 0;
}