#include <iostream>
#include <cstdlib>
#define Template template <typename T>
using namespace std;
Template class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Template class BinaryTree
{
private:
    int count = 0;
    TreeNode<T> *root;
    int getHeight(TreeNode<T> *node);
    void printInOrder(TreeNode<T> *node);
    void printPreOrder(TreeNode<T> *node);
    void printPostOrder(TreeNode<T> *node);
    void printLeafNodes(TreeNode<T> *node);

public:
    BinaryTree()
    {
        root = nullptr;
    }
    void insert(T val);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    void printLeafNodes();
    void showCount();
    int getHeight();
};

Template int BinaryTree<T>::getHeight(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return -1;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

Template int BinaryTree<T>::getHeight()
{
    return getHeight(root);
}

Template void BinaryTree<T>::printLeafNodes(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        cout << node->data << " ";
    }
    printLeafNodes(node->left);
    printLeafNodes(node->right);
}

Template void BinaryTree<T>::printLeafNodes()
{
    printLeafNodes(root);
}

Template void BinaryTree<T>::showCount()
{
    cout << "Number of Nodes: " << count << endl;
}

Template void BinaryTree<T>::insert(T val)
{

    TreeNode<T> *newNode = new TreeNode<T>(val);
    if (root == nullptr)
    {
        root = newNode;
        count++;
        return;
    }
    else
    {
        count++;
        TreeNode<T> *temp = root;
        while (true)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                break;
            }
            else if (temp->right == nullptr)
            {
                temp->right = newNode;
                break;
            }
            else
            {
                temp = (count % 2 == 0) ? temp->left : temp->right;
            }
        }
    }
}
Template void BinaryTree<T>::printInOrder(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

Template void BinaryTree<T>::printInOrder()
{
    printInOrder(root);
}

Template void BinaryTree<T>::printPreOrder(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

Template void BinaryTree<T>::printPreOrder()
{
    printPreOrder(root);
}

Template void BinaryTree<T>::printPostOrder(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
}

Template void BinaryTree<T>::printPostOrder()
{
    printPostOrder(root);
}

int main()
{
    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    cout << "Inorder traversal: ";
    tree.printInOrder();
    cout << endl;
    cout << "Preorder traversal: ";
    tree.printPreOrder();
    cout << endl;
    cout << "Postorder traversal: ";
    tree.printPostOrder();
    cout << endl;
    tree.showCount();
    cout << endl;
    cout << "The LEAVES are: ";
    tree.printLeafNodes();
    cout << endl;
    return 0;
}
