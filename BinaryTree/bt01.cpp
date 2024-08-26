#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int da)
    {
        this->data = da;
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

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = new Node(data);
    cout << "Enter data for inserting in left of: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of: " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(Node *root){
    if(root == nullptr){
        return;
    }
    

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
 }


int main()
{
    Node *root = nullptr;

    root = buildTree(root);
    // LevelOrderTransversal(root);
    inorder(root);
    return 0;
}