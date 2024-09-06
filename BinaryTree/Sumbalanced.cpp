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
    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *BuildTree(Node *root)
{
    int d;
    cout << "Enter data: " << endl;
    cin >> d;
    root = new Node(d);

    if (d == -1)
    {
        return nullptr;
    }

    cout << "Enter the data in left Node: " << d << endl;
    root->left = BuildTree(root->left);
    cout << "Enter the data in right Node: " << d << endl;
    root->right = BuildTree(root->right);

    return root;
}

/*void LevelOrderTransversal(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(nullptr);

    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!que.empty())
            {
                que.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                que.push(temp->left);
            }

            if (temp->right)
            {
                que.push(temp->right);
            }
        }
    }
}*/

/*void TransversalTree(Node *root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    TransversalTree(root->left);
    TransversalTree(root->right);
    // cout << endl;
}*/

/*void LevelOrderTransversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }

        else
        {
            cout << temp->data << ' ';
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}*/

void Inorder(Node *root){
    if(root == nullptr){
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}


int findSum(Node *root, bool &val) {
    
    if (root == nullptr) {
        return 0;
    }

    
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    
    int leftSum = findSum(root->left, val);
    int rightSum = findSum(root->right, val);

    
    if (leftSum + rightSum != root->data) {
        val = false;  
    }

    
    return root->data;
}


int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    bool val = true;
    findSum(root, val);
    if(val == true){
        cout << "true";
    }
    else {
            cout << "false";
    }
    return 0;
}

// 3 1 2 - 1 -1

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
