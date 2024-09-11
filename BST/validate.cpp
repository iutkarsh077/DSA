#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool searchInBST(Node *root, int x)
{
    // Write your code here.
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (x > root->data)
    {
        return searchInBST(root->right, x);
    }
    else
    {
        return searchInBST(root->left, x);
    }
}

bool searchInBST2(Node *root, int x)
{
    // Write your code here.
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (x > root->data)
    {
        return searchInBST(root->right, x);
    }
    else
    {
        return searchInBST(root->left, x);
    }
}

int minVal(Node *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }

    int val = minVal(root->left);
    return val;
}

void validate(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }

    validate(root->left, arr);
    arr.push_back(root->data);
    validate(root->right, arr);
}

Node *InsertAtBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = InsertAtBST(root->right, data);
    }

    else
    {
        root->left = InsertAtBST(root->left, data);
    }

    return root;
}

void BuildTree(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        cout << "Enter the data for BST: ";
        root = InsertAtBST(root, data);
        cin >> data;
    }
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == val)
    {
        // Zero child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // One Child
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != nullptr && root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Two child
        else if (root->left != nullptr && root->right != nullptr)
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}


bool isBSTValid(Node *root, int min, int max){
    if(root == nullptr){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBSTValid(root->left, min, root->data);
        bool right = isBSTValid(root->right, root->data, max);
        return left && right;
    }

    else{
        return false;
    }
}

int main()
{
    Node *root = nullptr;
    BuildTree(root);
    vector<int> arr;
    bool val = isBSTValid(root, INT_MIN, INT_MAX);
    cout << endl << endl;

    cout << val;

    return 0;
}