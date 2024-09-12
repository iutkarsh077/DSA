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

Node *InsertNode(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (root->data >= data)
    {
        root->right = InsertNode(root->right, data);
    }

    else
    {
        root->left = InsertNode(root->left, data);
    }

    return root;
}
void BuildTree(Node *&root)
{
    cout << "Enter the data: ";
    int d;
    cin >> d;
    cout << endl;
    while (d != -1)
    {
        root = InsertNode(root, d);
        cout << "Enter the data: ";
        cin >> d;
        cout << endl;
    }
}

void Inorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }

    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}

int main()
{
    Node *root = nullptr;
    BuildTree(root);
    vector<int> arr;
    Inorder(root, arr);

    int prec = -1;
    int succ = -1;
    int val = 5;
    for (int i = 0; i < arr.size(); i++)
    {
        if (val == arr[i])
        {
            if (i >= 1)
            {
                prec = arr[i - 1];
            }

            if (i < arr.size() - 1)
            {
                succ = arr[i + 1];
            }
        }
    }

    cout << endl;
    cout << "Predeccessor is: " << prec << endl;
    cout << "Successor is: " << succ << endl;
    return 0;
}