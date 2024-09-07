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
    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *BuildTree(Node *root)
{
    int d;
    cout << "Enter data: " << endl;
    cin >> d;
    root = new Node(d);

    if (d == -1)
    {
        return nullptr;
    }

    cout << "Enter the data in left Node: " << d << endl;
    root->left = BuildTree(root->left);
    cout << "Enter the data in right Node: " << d << endl;
    root->right = BuildTree(root->right);

    return root;
}

/*void LevelOrdertransversal(Node *root, vector<int> &vec)
{
    if (!root) return; // Edge case: empty tree

    queue<Node *> que;
    que.push(root);
    bool leftToRight = true;

    while (!que.empty())
    {
        int size = que.size(); // Number of nodes at the current level
        vector<int> level(size); // Temporary array to hold nodes at the current level

        for (int i = 0; i < size; i++)
        {
            Node *temp = que.front();
            que.pop();

            // Place the node in the correct position depending on the current direction
            int index = leftToRight ? i : size - 1 - i;
            level[index] = temp->data;

            // Push child nodes of the current node into the queue for the next level
            if (temp->left)
            {
                que.push(temp->left);
            }
            if (temp->right)
            {
                que.push(temp->right);
            }
        }

        // Add current level to the result
        for (int val : level)
        {
            vec.push_back(val);
        }

        // Switch direction for the next level
        leftToRight = !leftToRight;
    }
}*/

/*void LevelOrderTransversal(Node *root, vector<int> &vec)
{
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        for(int val: level){
            vec.push_back(val);
        }

        leftToRight = !leftToRight;
    }
}*/

void LevelOrderTransversal(Node *root, vector<int> &vec){
    if(root == nullptr){
        return;
    }

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i = 0; i < size; i++){
            Node *temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        for(int val : level){
            vec.push_back(val);
        }

        leftToRight = !leftToRight;
    }
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    // LevelOrderTransversal(root);
    // Inorder(root);
    vector<int> vec;
    LevelOrderTransversal(root, vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
