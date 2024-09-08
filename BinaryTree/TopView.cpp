#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    root = new Node(data);

    cout << "Enter data in left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data in right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void LeftView(Node *root, vector<int>&arr){
    if(root == nullptr){
        return;
    }

    LeftView(root->left, arr);
    arr.push_back(root->data);
}


void RightView(Node *root, vector<int>&arr){
    if(root == nullptr){
        return;
    }

    arr.push_back(root->data);
    RightView(root->right, arr);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    vector<int> arr;
    LeftView(root, arr);
    RightView(root->right, arr);

    cout << endl;
    cout << endl;
    for(int val : arr){
        cout << val << " ";
    }
    return 0;
}

// 1 2 -1 3 -1 -1 4 -1 -1
// 1 2 3 -1 -1 4 -1 -1 4 -1 9 8 -1 -1 -1
// 1 2 -1 -1 4 -1 -1
// 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
// 10 20 40 -1 -1 60 -1 -1 30 90 -1 -1 100 -1 -1
// 1 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

// 2 1 10 -1 -1 3 -1 -1 6 4 9 -1 5