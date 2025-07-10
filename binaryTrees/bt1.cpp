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
    int data;
    cout << "Enter your data: ";
    cin >> data;
    cout << endl;

    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data fro inserting in left of  " << data << endl;
    root->left = BuiltTree(root->left);
    cout << "Enter data fro inserting in right of  " << data << endl;
    root->right = BuiltTree(root->right);
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
            if(!q.empty()){
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
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}