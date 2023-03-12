#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;



class Graph{
    public:
        int left;
        int right;
};

class Node
{
    int date;
    Node *Left;
    Node *Right;
    Node *Parent;
};
class Vertex
{
public:
    int inTime;
    string status;
    Node inVertex[13];
    Node outVertex[13];
    int value;
    Vertex(int v)
    {
        this->value = v;
    };
    void hasOutNeighbor(){};
    void hasInNeighbor(){};
    void hasNeighbor(){};
    void getOutNeighbors(){};
    void getInNeighbors(){};
    void addOutNeighbor(){};
    void addInNeighbor(){};
};
int DFS_helper(Vertex  w,int currentTime,bool verbose ){

    if (verbose){
        cout << "Time", currentTime, ":\t entering", w;
    }
    w.inTime = currentTime;
    currentTime += 1;
    w.status = "inprogress";
    for v in w.getOutNeighbors():
        if v.status == "unvisited":
            currentTime = DFS_helper(v, currentTime, verbose)
            currentTime += 1
    w.outTime = currentTime
    w.status = "done"
    if verbose:
        print("Time", currentTime, ":\t leaving", w)
    return currentTime
}
        
def DFS( w, G, verbose=False ):
    for v in G.vertices:
        v.status = "unvisited"
        v.inTime = None
        v.outTime = None
    return DFS_helper( w, 0, verbose )

void DFS() {}
void BFS() {}

int main()
{

    return 0;
}

 void BFS(w, G):
    for v in G.vertices:
        v.status = "unvisited"
    n = len(G.vertices)
    Ls = [ [] for i in range(n) ]
    Ls[0] = [w]
    w.status = "visited"
    for i in range(n):
        for u in Ls[i]:
            for v in u.getOutNeighbors():
                if v.status == "unvisited":
                    v.status = "visited"
                    Ls[i+1].append(v)
    return Ls