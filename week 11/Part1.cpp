#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
    bool color;

    Node(int data)
    {
        this->data = data;
    }
};

class BST
{
private:
    Node *root = NULL;

public:
    bool isEmpty()
    {
        return this->root == NULL;
    }
    Node *getTree()
    {
        return root;
    }
    void insert(int x)
    {
        Node *newNode = new Node(x);
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;

        if (isEmpty())
        {
            root = newNode;
            newNode->parent = NULL;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (x < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newNode;
                        newNode->parent = temp;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newNode;
                        newNode->parent = temp;
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
    void InOrderTraversal(Node *T)
    {
        if (T != NULL)
        {
            InOrderTraversal(T->left);
            cout << T->data << " ";
            InOrderTraversal(T->right);
        }
    }
    void PreOrderTraversal(Node *T)
    {
        if (T != NULL)
        {
            cout << T->data << " ";
            PreOrderTraversal(T->left);
            PreOrderTraversal(T->right);
        }
    }
    void PostOrderTraversal(Node *T)
    {
        if (T != NULL)
        {
            PostOrderTraversal(T->left);
            PostOrderTraversal(T->right);
            cout << T->data << " ";
        }
    }
    Node *findNode(int x)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (x == temp->data)
            {
                return temp;
            }
            else if (x < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return NULL;
    }
    bool deleteNode(int x)
    {
        Node *temp = findNode(x);
        if (temp == NULL)
        {
            return false;
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = NULL;
                }
                else
                {
                    temp->parent->right = NULL;
                }
                delete temp;
            }
            else if (temp->left == NULL || temp->right == NULL)
            {
                if (temp->left == NULL)
                {
                    if (temp->parent->left == temp)
                    {
                        temp->parent->left = temp->right;
                    }
                    else
                    {
                        temp->parent->right = temp->right;
                    }
                    temp->right->parent = temp->parent;
                    delete temp;
                }
                else
                {
                    if (temp->parent->left == temp)
                    {
                        temp->parent->left = temp->left;
                    }
                    else
                    {
                        temp->parent->right = temp->left;
                    }
                    temp->left->parent = temp->parent;
                    delete temp;
                }
            }
            else
            {
                Node *successor = temp->right;
                while (successor->left != NULL)
                {
                    successor = successor->left;
                }
                temp->data = successor->data;
                if (successor->parent->left == successor)
                {
                    successor->parent->left = successor->right;
                }
                else
                {
                    successor->parent->right = successor->right;
                }
                if (successor->right != NULL)
                {
                    successor->right->parent = successor->parent;
                }
                delete successor;
            }
            return true;
        }
    }
    int NumberOfNodes(Node *T)
    {
        if (T == NULL)
            return 0;
        else
            return 1 + NumberOfNodes(T->left) + NumberOfNodes(T->right);
    }
    bool leafNodes(Node *T)
    {
        int count = 0;
        while (T != NULL)
        {
            if (T->left == NULL && T->right == NULL)
            {
                count++;
            }
            T = T->right;
        }
        if (count == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int height(Node *T)
    {
        if (T == NULL)
        {
            return 0;
        }
        else
        {
            int height_left = height(T->left);
            int height_right = height(T->right);
            if (height_left > height_right)
            {
                return height_left + 1;
            }
            else
            {
                return height_right + 1;
            }
        }
    }
};
class RBTree : BST
{
private:
    Node *root;

public:
    RBTree()
    {
        root = NULL;
    }
    RBTree(int arr[], int size) {}
    void visualizeTree(Node *T) {}

    Node *Insert(Node *T, Node *z)
    {
        Node *y = NULL;
        Node *x = T->parent;
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == NULL)
        {
            T->parent = z;
        }
        else if (z->data < y->data)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
        z->left = NULL;
        z->right = NULL;
        z->color = 1;
        RB_INSERT_FIXUP(z);
    }

    void RB_INSERT_FIXUP(Node *z)
    {

        while (z->parent->color == true)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *y = z->parent->parent->right;
                if (y->color == true)
                {
                    z->parent->color = false;
                    y->color = false;
                    z->parent->parent->color = true;
                    z = z->parent->parent;
                }
                else if (z == z->parent->right)
                {
                    z = z->parent;
                    LEFT_ROTATE(root, z);
                }
                z->parent->color = false;
                z->parent->parent->color = true;
                RIGHT_ROTATE(root, z->parent, z);
            }
        }
    };

    void LEFT_ROTATE(Node *T, Node *z)
    {
        Node *y = z->right;
        z->right = y->left;
        if (y->left != NULL)
        {
            y->left->parent = z;
        }
        y->parent = z->parent;
        if (z->parent == NULL)
        {
            root = y;
        }
        else if (z == z->parent->left)
        {
            z->parent->left = y;
        }
        else
        {
            z->parent->right = y;
            y->left = z;
            z->parent = y;
        }
    }
    void RIGHT_ROTATE(Node *T, Node *z, Node *a)
    {
        Node *y = z->left;
        z->left = y->right;
        if (y->right != NULL)
        {
            y->right->parent = z;
        }
        y->parent = z->parent;
        if (z->parent == NULL)
        {
            root = y;
        }
        else if (z == z->parent->right)
        {
            z->parent->right = y;
        }
        else
        {
            z->parent->left = y;
            y->right = z;
            z->parent = y;
        }
    }

    Node RB_Transplant(Node *T, Node *u, Node *v)
    {
        if (u->parent == NULL)
        {
            T = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    Node *Delete(Node *T, Node *z)
    {
        Node *y = z;
        Node y_original_color = y->color;
        if (z->left == NULL)
        {
            z = z->right;
            RB_Transplant(T, z, z->right);
        }
        else if (z->right == NULL)
        {
            z = z->left;
            RB_Transplant(T, z, z->left);
        }
        else
        {
            y = TREE_MINIMUM(z->right);
            y_original_color = y->color;
            z = y->right;
            if (y->parent == z)
            {
                z->parent = y;
            }
            else
            {
                RB_Transplant(T, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            RB_Transplant(T, z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
    }
    Node *TREE_MINIMUM(Node *T)
    {
    }

    ~RBTree()
    {
    }
};

class AvlTree : BST
{
public:
    AvlTree(void);
    AvlTree(int arr[], int size);
    ~AvlTree(void);
    void visualizeTree(Node *T);
    Node *Insert(int x) {}
    Node *Delete(int x) {}

private:
    Node *root;
};
void main()
{
}