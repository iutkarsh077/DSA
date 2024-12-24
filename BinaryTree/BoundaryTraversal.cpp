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
    }data = val;
        left = NULL;
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

void leftNode(Node *root, vector<int> &arr)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    arr.push_back(root->data);

    if (root->left)
    {
        leftNode(root->left, arr);
    }
    else
    {
        leftNode(root->right, arr);
    }
}

void LeafNode(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        arr.push_back(root->data);
        return;
    }

    LeafNode(root->left, arr);
    LeafNode(root->right, arr);
}

void RightNode(Node *root, vector<int> &arr)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->right)
    {
        RightNode(root->right, arr);
    }
    else
    {
        RightNode(root->left, arr);
    }

    arr.push_back(root->data);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    vector<int> arr;
    leftNode(root, arr);
    LeafNode(root, arr);
    RightNode(root, arr);
    arr.pop_back();
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// 1 2 -1 3 -1 -1 4 -1 -1
// 1 2 3 -1 -1 4 -1 -1 4 -1 9 8 -1 -1 -1
// 1 2 -1 -1 4 -1 -1
// 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
// 4 10 -1 5 5 -1 6 7 -1 8 8 -1 8 11 -1 3 4 -1 1 3 -1 8 6 -1 11 11 -1 5 8


class Solution {
public:

    void leftNode(Node *root, vector<int> &arr)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    arr.push_back(root->data);

    if (root->left)
    {
        leftNode(root->left, arr);
    }
    else
    {
        leftNode(root->right, arr);
    }
}

void LeafNode(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        arr.push_back(root->data);
        return;
    }

    LeafNode(root->left, arr);
    LeafNode(root->right, arr);
}

void RightNode(Node *root, vector<int> &arr)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->right)
    {
        RightNode(root->right, arr);
    }
    else
    {
        RightNode(root->left, arr);
    }

    arr.push_back(root->data);
}


    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> arr;
        
          if(root == NULL)
            return arr;
            
        arr.push_back(root->data);
        
        
    leftNode(root->left, arr);
    LeafNode(root->left, arr);
    LeafNode(root->right, arr);
    RightNode(root->right, arr);
    return arr;
    }
};