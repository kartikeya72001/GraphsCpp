#include <iostream>
#include <list>
using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printList()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int x:l[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,2);
    g.addEdge(1,3);
    g.printList();
    return 0;
}
