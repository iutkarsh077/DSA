#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    root = new Node(data);

    cout << "Enter data in left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data in right of " << data << endl; 
    root->right = BuildTree(root->right);

    return root;
}

vector<vector<int>> LevelTraversal(Node *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    bool leftToRight = true;
    vector<int> tempArr;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            if (leftToRight)
            {
                ans.push_back(tempArr);
            }

            else
            {
                reverse(tempArr.begin(), tempArr.end());
                ans.push_back(tempArr);
            }

            leftToRight = !leftToRight;
            tempArr.clear();

            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            tempArr.push_back(temp->data);

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
    return ans;
}

int main()
{
    Node *root = nullptr;
    root = BuildTree(root);
    vector<vector<int>> ans = LevelTraversal(root);

    cout << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// 1 2 -1 3 -1 -1 4 -1 -1
//1 2 3 -1 -1 4 -1 -1 4 -1 9 8 -1 -1 -1
// 1 2 -1 -1 4 -1 -1