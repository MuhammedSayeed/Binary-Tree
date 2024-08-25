#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {

        left = right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BinaryTree
{

private:
    TreeNode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    void insert(int _data)
    {
        TreeNode *newNode = new TreeNode(_data);

        if (this->root == NULL)
        {
            this->root = newNode;
            return;
        }

        queue<TreeNode *> q;
        q.push(this->root);
        while (!q.empty())
        {
            TreeNode *currentNode = q.front();
            q.pop();

            if (currentNode->left == NULL)
            {
                currentNode->left = newNode;
                break;
            }
            else
            {
                q.push(currentNode->left);
            }
            if (currentNode->right == NULL)
            {
                currentNode->right = newNode;
                break;
            }
            else
            {
                q.push(currentNode->right);
            }
        }
    }
    void print()
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *currentNode = q.front();
            q.pop();
            cout << currentNode->data << " ";

            if (currentNode->left != NULL)
            {
                q.push(currentNode->left);
            }

            if (currentNode->right != NULL)
            {
                q.push(currentNode->right);
            }
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}