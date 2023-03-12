#include <iostream>
#include <conio.h>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;

public:
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->parent = NULL;
        this->right = NULL;
    }
    ~Node();
};

void main()
{
}