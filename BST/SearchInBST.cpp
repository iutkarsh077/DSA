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
int minVal(Node *root){
    if(root->left == nullptr){
        return root->data;
    }

    int val = minVal(root->left);
    return val;
}

Node *deleteFromBST(Node *root, int val){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == val){
        //Zero child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // One Child
        if(root->left != nullptr && root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if(root->right != nullptr && root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //Two child
        else if(root->left != nullptr && root->right != nullptr){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    return 0;
}