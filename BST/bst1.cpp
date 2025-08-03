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

void LevelOrderTransversal(Node *root)
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
            cout << temp->data << " ";
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
}

int main()
{
    Node *root = nullptr;
    BuildTree(root);
    LevelOrderTransversal(root);
    return 0;
}