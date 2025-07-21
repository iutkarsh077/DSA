#include <iostream>
#include <vector>
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
    cout << "Enter data: ";
    int val;
    cin >> val;

    root = new Node(val);
    if (val == -1)
    {
        return nullptr;
    }

    cout << endl;

    cout << "Enter val for the left of " << val << " " << endl;
    root->left = BuiltTree(root->left);
    cout << "Enter val for the right of " << val << " " << endl;
    root->right = BuiltTree(root->right);
    return root;
}

 int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int result = max(left, right) + 1;

        return result;
    }

void Inorder(Node *&root)
{
    if (root == nullptr)
        return;

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

vector<int> ZigZag(Node *root)
{
    vector<int> result;
    bool leftToRight = true;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        for (auto i : ans)
        {
            result.push_back(i);
        }
        leftToRight = !leftToRight;
    }

    return result;
}

vector<int> ZigZagAgain(Node *root)
{
    queue<Node *> q;
    q.push(root);
    bool LeftToRight = true;
    vector<int> result;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = LeftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        for (auto i : ans)
        {
            result.push_back(i);
        }
        LeftToRight = !LeftToRight;
    }
    return result;
}

void TransverseLeft(Node *root, vector<int> &ans)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    ans.push_back(root->data);
    if (root->left)
    {
        TransverseLeft(root->left, ans);
    }
    else
    {
        TransverseLeft(root->right, ans);
    }
}

void TransverseLeaf(Node *root, vector<int> &ans)
{
    if(root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
        return;
    }

   TransverseLeaf(root->left, ans);
        TransverseLeaf(root->right, ans);

}

void TransverseRight(Node *root, vector<int> &ans)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if (root->right)
    {
        TransverseRight(root->right, ans);
    }
    else
    {
        TransverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

 bool isSameTree(Node* p, Node* q) {
        if(p == nullptr && q == nullptr) return true;

        if(p == nullptr || q == nullptr) return false;

        if(p->data != q->data) return false;

        bool ans = isSameTree(p->left, q->left);
        bool ans2 = isSameTree(p->right, q->right);

        if(ans == false || ans2 == false) return false;
        return true;
    }

int main()
{
    Node *root = nullptr;
    BuiltTree(root);
    cout << endl;
    vector<int> ans;
    if (root) ans.push_back(root->data);
    TransverseLeft(root->left, ans);
    TransverseLeaf(root, ans);
    TransverseRight(root->right, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1