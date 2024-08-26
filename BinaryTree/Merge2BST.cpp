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
        left = nullptr;
        right = nullptr;
    }
};
void MergeTwoArray(vector<int> arr1, vector<int> arr2, vector<int> &arr3)
{
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        arr3.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        arr3.push_back(arr2[j]);
        j++;
    }
}

Node *InsertBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = InsertBST(root->right, data);
    }

    else
    {
        root->left = InsertBST(root->left, data);
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

int main()
{
    vector<int> arr1 = {2, 1, 8, 6, 3, 4, 9, 7};
    vector<int> arr2 = {6, 9, 1, 3, 7, 2, 8, 4, 56};

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> arr3;
    MergeTwoArray(arr1, arr2, arr3);

    int i = 0;
    Node *root = nullptr;
    while (i < arr3.size())
    {
        root = InsertBST(root, arr3[i]);
        i++;
    }

    LevelOrderTransversal(root);
    return 0;
}
