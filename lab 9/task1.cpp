#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
private:
    Node *Head;

public:
    bool isEmpty()
    {
        return Head == NULL;
    }
    void print()
    {
        Node *p = this->Head;
        while (p != NULL)
        {
            cout << p->data << endl;
        }
    }
    Node *search(int x)
    {
        Node *p = Head;
        while (p != NULL)
        {
            if (p->data == x)
            {
                return p;
            }
        }
        return NULL;
    }
    bool insertAtHead(int x)
    {
        Node *N = new Node(x);
        if (Head != NULL)
        {
            N->next = Head;
        }
        return true;
    }

    void insertTail(int x)
    {
        Node *N = new Node(x);
        Node *p = Head;
        while (p->next == NULL)
        {
            p = p->next;
        }
        p->next = N;
    }
    void Delete(int x)
    {
        Node *d = Head;
        Node *p = Head;
        while (d->next->next != NULL)
        {
            if (d->data == x)
            {
                p = d->next;
                d->next = p;
                cout << "Found ";
            }
            else
            {
                cout << " not Found ";
            }
        }
    }

    Node *insertNode(int index, int x)
    {
        int index1 = 0;
        Node *d = Head;
        Node *p = Head;
        Node *newAdd = new Node(x);
        while (d->next != NULL)
        {
            index1++;
            if (index == index1)
            {
                p = d->next;
                d->next = newAdd;
                newAdd->next = p;
            }
        }
        if (d->data == x)
        {
            p = d->next;
            d->next = p;
        }
        else
        {
            d = d->next;
        }
    }
    void Update(int x)
    {
        Node *d = Head;
        while (d->next != NULL)
        {
            if (d->data == x)
            {
                d->data = x;
                cout << "Found ";
            }
            else
            {
                cout << "not Found ";
            }
        }
    }
    Node *reverseList() {}
    Node *sortList(Node *list) {}
    Node *removeDuplicates(Node *list) {}
    Node *mergeLists(Node *list1, Node *list2) {}
    Node *interestLists(Node *list1, Node *list2) {}
    int length()
    {
        int index = 0;
        Node *d = Head;
        while (d->next != NULL)
        {
            index++;
        }
        return index;
    }
};

void main()
{
    LinkedList link;
    link.insertAtHead(4);
    link.insertNode(2, 2);
    int len = link.length();
    cout << len;
    link.Update(2);
}