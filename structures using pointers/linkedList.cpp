
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

// class LinkedList
// {
// private:
//     Node *Head;

// public:
//     void print()
//     {
//         Node *p = this->Head;
//         while (p != NULL)
//         {
//             cout << p->data << endl;
//         }
//     }
//     Node *search(int key)
//     {
//         Node *p = Head;
//         while (p != NULL)
//         {
//             if (p->data == key)
//             {
//                 return p;
//             }
//         }
//         return NULL;
//     }
//     bool HeadInsert(int key)
//     {
//         Node *N = new Node(key);
//         if (Head != NULL)
//         {
//             N->next = Head;
//         }
//         return true;
//     }
//     void insertTail(int key)
//     {
//         Node *N = new Node(key);
//         Node *p = Head;
//         while (p->next == NULL)
//         {
//             p = p->next;
//         }
//         p->next = N;
//     }
//     void Delete(int key)
//     {
//         Node *d = Head;
//         Node *p = Head;
//         while (d->next->next != NULL)
//         {
//             if (d->data == key)
//             {
//                 p = d->next;
//                 d->next = p;
//                 cout << "Found ";
//             }
//             else
//             {
//                 cout << " not Found ";
//             }
//         }
//     }

//     void Update(int key)
//     {
//         Node *d = Head;
//         while (d->next != NULL)
//         {
//             if (d->data == key)
//             {
//                 d->data = key;
//                 cout << "Found ";
//             }
//             else
//             {
//                 cout << "not Found ";
//             }
//         }
//     }

//     int length()
//     {
//         int index = 0;
//         Node *d = Head;
//         while (d->next != NULL)
//         {
//             index++;
//         }
//         return index;
//     }
// };

void main()
{
    Node N;
    LinkedList lk;
    cout << ;
}
