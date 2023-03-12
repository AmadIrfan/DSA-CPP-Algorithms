#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
    Node(int data)
    {
        this->Data = data;
    }
};
class linklist
{
private:
    Node *Head;

public:
    void print_all_data()
    {
        Node *p = Head;
        while (p != NULL)
        {
            cout << p->Data << endl;
            p = p->Next;
        }
    }

    void Delete(int key)
    {
        Node *d = Head;
        while (d->Next != NULL)
        {
            if (d->Data == key)
            {
                d = d->Next;
                cout << " Founded ";
            }
            else
            {
                cout << " not Founded ";
            }
        }
    }
    void search(int key)
    {
        Node *p = Head;
        while (p != NULL)
        {
            if (p->Data == key)
            {
                cout << "Founded ";
            }
            else
            {
                cout << " NotFounded ";
            }
        }
    }

    bool insertathead(int key)
    {
        Node *p = new Node(key);
        if (Head != NULL)
        {
            Head = p;
        }
        else
        {
            p->Next = Head;
        }
    }
    void insertTail(int key)
    {
        Node *q = new Node(key);
        Node *p = Head;
        while (p->Next == NULL)
        {
            p = p->Next;
        }
        p->Next = q;
    }
    void printreverse(Node *Head)
    {
        if (Head == NULL)
        {
            return printreverse(Head->Next);
            cout << Head->Data;
        }
    }
};

int main()
{

    return 0;
}