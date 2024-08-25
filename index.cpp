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
    int Height() { return internalHeight(this->root); }
    int internalHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(internalHeight(node->left), internalHeight(node->right));
    }

    void PreOrder()
    {
        internalPreOrder(root);
        cout << endl;
    }

    void internalPreOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " -> ";
        internalPreOrder(node->left);
        internalPreOrder(node->right);
    }

    void InOrder()
    {
        internalInOrder(root);
        cout << endl;
    }

    void internalInOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        internalInOrder(node->left);
        cout << node->data << " -> ";
        internalInOrder(node->right);
    }

    void PostOrder()
    {
        internalPostOrder(root);
        cout << endl;
    }

    void internalPostOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        internalPostOrder(node->left);
        internalPostOrder(node->right);
        cout << node->data << " -> ";
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