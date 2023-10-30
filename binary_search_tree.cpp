#include <iostream>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            TreeNode *temp = root;
            while (true)
            {
                if (val < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void printInOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            printInOrder(node->left);
            cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void printPreOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }

    void printPostOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            printPostOrder(node->left);
            printPostOrder(node->right);
            cout << node->data << " ";
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);
    tree.insert(6);
    tree.insert(8);
    cout << "Inorder traversal: ";
    tree.printInOrder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.printPreOrder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.printPostOrder(tree.root);
    cout << endl;

    return 0;
}
