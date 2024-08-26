#include <bits/stdc++.h>
using namespace std;

/*class Node
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

Node *BuildTree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }
    cout << "enter data for left of: " << data << endl;
    root->left = BuildTree(root->left);

    cout << "enter data for right of: " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void Transversal(Node *root)
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


void TreeTransversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    TreeTransversal(root->left);

    TreeTransversal(root->right);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    Transversal(root);
    return 0;
}*/
/*
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        Node *left = nullptr;
        Node *right = nullptr;
    }
};

Node *BuildTree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for left of: " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data for right of: " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void LevelTransversal(Node *root)
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

void InorderTransversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data<< " ";
    InorderTransversal(root->left);
    InorderTransversal(root->right);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    // LevelTransversal(root);
    InorderTransversal(root);
    return 0;
}
*/

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

void LevelTransversal(Node *root)
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

Node *Buildtree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = Buildtree(root->left);
    cout << "Enter data for right of " << data << endl;

    root->right = Buildtree(root->right);

    return root;
}

int main()
{
    Node *root = nullptr;
    root = Buildtree(root);
    cout << "Left data is: " << root->right->data;
    // LevelTransversal(root);
}

// 1 2 -1 3 -1 -1 4 -1 -1
//1 2 3 -1 -1 4 -1 -1 4 -1 9 8 -1 -1 -1
// 1 2 -1 -1 4 -1 -1