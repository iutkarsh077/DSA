#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;


bool searchInBST(BinaryTreeNode<int> *root, int x) {
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