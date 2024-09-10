#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;


    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool searchInBST(Node *root, int x) {
    // Write your code here.
    if (root == nullptr) {
      return false;
    }

    if (root->data == x){
        return true;
    }

    if(x > root->data){
        return searchInBST(root->right, x);
    }       
    else{
        return searchInBST(root->left, x);
    }
}

int main() {
    return 0;
}