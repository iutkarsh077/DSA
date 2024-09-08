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

void LeftNode(Node *root, vector<int> &arr){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }

    arr.push_back(root->data);
    if(root->left){
        LeftNode(root->left, arr);
    }
    else{
        LeftNode(root->right, arr);
    }
}


void LeafNode(Node *root, vector<int> &arr){
    if(root == nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        arr.push_back(root->data);
    }

    LeafNode(root->left, arr);
    LeafNode(root->right, arr);
}

void RightNode(Node *root, vector<int> &arr){
     if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }

    if(root->right){
        RightNode(root->right, arr);
    }
    else{
        RightNode(root->left, arr);
    }
    arr.push_back(root->data);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    vector<int> arr;
    LeftNode(root, arr);
    LeafNode(root, arr);
    RightNode(root, arr);
    arr.pop_back();
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// 1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1