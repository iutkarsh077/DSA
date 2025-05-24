#include <bits/stdc++.h>
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
        left = nullptr;
        right = nullptr;
    }
};



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

Node *BSTInsert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = BSTInsert(root->right, data);
    }
    else
    {
        root->left = BSTInsert(root->left, data);
    }

    return root;
}

void Inorder(Node *root, int &max) // Inorder also do sorting
{
    if (root == nullptr)
    {
        return;
    }

    if (max < root->data)
    {
        max = root->data;
    }
    Inorder(root->left, max);
    cout << root->data << " ";
    Inorder(root->right, max);
}

void minOrder(Node *root, int &min) // Inorder also do sorting
{
    if (root == nullptr)
    {
        return;
    }

    if (min > root->data)
    {
        min = root->data;
    }
    minOrder(root->left, min);
    // cout << root->data << " ";
    minOrder(root->right, min);
}

void InsertInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = BSTInsert(root, data);
        cin >> data;
    }
}

Node* minVal(Node *root)
{
    Node *temp = root;

    while(temp->left != nullptr){
        temp = temp->left;
    }

    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == val)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = minVal(root->right)->data;
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

int main()
{
    Node *root = nullptr;
    cout << "Enter your data for BST: " << endl;
    InsertInput(root);
    LevelOrderTransversal(root);
    int max = -1;
    int min = INT_MAX;
    Inorder(root, max);
    minOrder(root, min);
    cout
        << " Max Value is: " << max << endl;
    cout
        << " Min Value is: " << min << endl;

    deleteFromBST(root, 12);
    cout << endl;
    LevelOrderTransversal(root);
    return 0;
}