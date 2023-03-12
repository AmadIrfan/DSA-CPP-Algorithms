#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;
class Node
{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
};
class BST
{
    Node *root;

public:
    BST(int arr[], int size);
    bool isEmpty()
    {
        if (root == NULL)
        {
            return root;
        }
    }
    Node *getTree()
    {
    }
    Node *insertNode(int x)
    {
        Node *T = root;
        while (T->parent != NULL)
        {
            if (T->parent->left->data < x)
            {
            }
            else if (
                T->parent->right->data > x)
            {
                T->parent->right->data = x;
            }
        }
    }
    Node *findNode(int x)
    {
        Node *T = root;
        while (T->data != x)
        {
            if (T->left->data == x)
            {
                return T;
            }
            else if (T->right->data == x)
            {
                return T;
            }
        }
        return NULL;
    }
    bool deleteNode(int x)
    {
    }

    ~BST(void);
};
int main()
{
    return;
}

// binary search tree ?
