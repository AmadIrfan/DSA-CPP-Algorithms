
#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

class C_pointers
{
private:
    int age;
    string name;

    char g = 'A';

public:
    void getData()
    {
        cout << "My name is "<< name;
        cout << "  my age is "<< age;
        cout << " lucky number is "<< g;
    }
    void setData(string na, int ag, char sdv)
    {
        name = na;
        age = ag;
        g = sdv;
    }
};

int main()
{
    C_pointers cp;
    C_pointers *ptr=new C_pointers[5];
    
    ptr->setData("amad", 21, 'a');
    ptr->getData();
    cout<<endl;
    
    ptr->setData("saad",23,'s');
    ptr->getData();
    cout<<endl;
    
    ptr->setData("jawad",12,'j');
    ptr->getData();
    // pointer in c++
    cout<<endl;
    int a = 123;
    int *b = &a;
    int **c;
    c = &b;
    delete  &a;
    cout << &a << " " << a << " " << &b << " " << b << " " << *b << endl;
    cout << c << " " << *c;
    return 0; 
}