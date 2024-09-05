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
        this->left = nullptr;
        this->right = nullptr;
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

        else{
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
}

Node *BuildTree(Node *&root)
{
    int d;
    cout << "Enter your Data: ";
    cin >> d;
    cout << endl;
    root = new Node(d);

    if (d == -1)
    {
        return nullptr;
    }

    cout << "Enter data in left of Node " << d << " ";
    root->left = BuildTree(root->left);
    cout << endl;
    cout << "Enter data in right of Node " << d << " ";
    root->right = BuildTree(root->right);
    cout << endl;
    return root;
}


Node *BuildTree2(Node *&root)
{
    int d;
    cout << "Enter your Data: ";
    cin >> d;
    cout << endl;
    root = new Node(d);

    if (d == -1)
    {
        return nullptr;
    }

    cout << "Enter data in left of Node " << d << " ";
    root->left = BuildTree(root->left);
    cout << endl;
    cout << "Enter data in right of Node " << d << " ";
    root->right = BuildTree(root->right);
    cout << endl;
    return root;
}

void Inorder(Node *root){
    if(root == nullptr){
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    LevelOrderTransversal(root);
    Inorder(root);
    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1