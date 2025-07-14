#include <iostream>
#include<queue>
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

Node *BuiltTree(Node *&root){
    cout << "Enter data: ";
    int val;
    cin >> val;

    root = new Node(val);
    if(val == -1){
        return nullptr;
    }


    cout << endl;

    cout << "Enter val for the left of " << val << " " << endl;
    root->left = BuiltTree(root->left);
    cout << "Enter val for the right of " << val << " " << endl;
    root->right = BuiltTree(root->right);
    return root;
}

void Inorder(Node *&root){
    if(root == nullptr) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}


void LevelOrderTransversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }

        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = nullptr;
    BuiltTree(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    LevelOrderTransversal(root);
    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1