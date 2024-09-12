#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int d;
    Node *left;
    Node *right;

    Node(int data){
        this->d = data;
        left = nullptr;
        right = nullptr;
    }
};

Node *InsertAtTree(Node *root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

   if (data > root->d)
    {
        root->right = InsertAtTree(root->right, data);
    }

    else
    {
        root->left = InsertAtTree(root->left, data);
    }

    return root;
}

void BuildTree(Node *&root){
    int d;
    cout << "Enter data: " << " ";
    cin >> d;

    while(d != -1){
        cout << endl;
        root = InsertAtTree(root, d);
        cout << "Enter data: " << " ";
        cin >> d;
    }
}

void SumAtK(Node *root, vector<int> &arr){
    if(root == nullptr){
        return;
    }

    SumAtK(root->left, arr);
    arr.push_back(root->d);
    SumAtK(root->right, arr);
}

int main() {
    Node *root = nullptr;
    BuildTree(root);
    vector<int> arr;
    SumAtK(root, arr);

    cout << endl;
    for(int i = 0;  i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}