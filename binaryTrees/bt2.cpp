#include <iostream>
#include <queue>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *BuiltTree(Node *&root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    cout << endl;

    root = new Node(data);
    if (data == -1)
        return nullptr;


    cout << "Enter the data for left of " << data << " : ";
    root->left = BuiltTree(root->left);
    cout << "Enter the data for right of " << data << " : ";
    root->right = BuiltTree(root->right);

    return root;
}

void PostOrder(Node *&root){
    if(root == nullptr){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void PreOrder(Node *&root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(Node *&root){
    if(root == nullptr){
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
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

    BuiltTree(root);
    LevelOrderTransversal(root);
    cout << endl << "In Order is: ";
    Inorder(root);
    cout << endl << "Post Order is: ";
    PostOrder(root);

    cout << endl << "Pre Order is: ";
    PreOrder(root);
    return 0;
}