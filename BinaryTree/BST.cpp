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

void insertInput(Node *&root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    while (data != -1)
    {
        root = BSTInsert(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = nullptr;
    insertInput(root);
    cout << endl;
    LevelOrderTransversal(root);
    return 0;
}