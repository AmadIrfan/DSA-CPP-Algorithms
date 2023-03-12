#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class stack
{
    int asd;

public:
    stack()
    {
    }
    stack(int s)
    {
        this->asd = s;
        cout << this->asd << endl;
    }
    int arr[5] = {13, 23, 33, 42, 52};
    int a[20];
    int c = 2;
    void push(int x)
    {
        c++;
        a[c] = x;
    }
    int pop()
    {
        int temp = a[c];
        a[c] = -1;
        c = c - 1;
        return temp;
    }
};

int main()
{
    stack a;
    a.push(10);
    cout << a.pop();
    return 0;
}