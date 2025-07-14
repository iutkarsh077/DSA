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



void BuildTree2(Node *&root)
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

Node *LCAInBST(Node *root, int p, int q){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data < p && root->data < q){
        return LCAInBST(root->right, p, q);
    }


    if(root->data > p && root->data > q){
        return LCAInBST(root->left, p, q);
    }

    return root;
}

Node *LCAInBST(Node *root, int p, int q){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data < p && root->data < q){
        return LCAInBST(root->right, p, q);
    }


    if(root->data > p && root->data > q){
        return LCAInBST(root->left, p, q);
    }

    return root;
}

/*int main()
{
    Node *root = nullptr;
    BuildTree(root);
    vector<int> arr;
    Inorder(root, arr);

    /*int prec = -1;
    int succ = -1;
    int val = 5;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < val)
        {
            prec = arr[i];
        }

        if (arr[i] > val)
        {
            succ = arr[i];
            break; 
        }
    }
    cout << endl;
    cout << "Predeccessor is: " << prec << endl;
    cout << "Successor is: " << succ << endl;


    Node *d = LCAInBST(root, 1, 3);

    cout << endl;
    cout << d->data;
    return 0;
}*/


int main()
{
    Node *root = nullptr;
    BuildTree(root);
    vector<int> arr;
    Inorder(root, arr);

    /*int prec = -1;
    int succ = -1;
    int val = 5;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < val)
        {
            prec = arr[i];
        }

        if (arr[i] > val)
        {
            succ = arr[i];
            break; 
        }
    }
    cout << endl;
    cout << "Predeccessor is: " << prec << endl;
    cout << "Successor is: " << succ << endl;*/


    Node *d = LCAInBST(root, 1, 3);

    cout << endl;
    cout << d->data;
    return 0;
}
