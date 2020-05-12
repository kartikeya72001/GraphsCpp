#include <iostream>
#include<queue>
#include<map>
#include<list>

using namespace std;

class Graph{
    list<int> *l;
    int v;
public:
    Graph(int v){
        this->v = v;
        this->l = new list<int>[v];
    }
    void addEdge(int x, int y, bool bi = true){
        l[x].push_back(y);
        if(bi)
            l[y].push_back(x);
    }

    bool cycleHelp(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true;

        for(int nbr:l[node])
        {
            if(stack[nbr]==true)
                return true;
            else if(visited[nbr]==false)
            {
                bool cycle = cycleHelp(nbr,visited,stack);
                if(cycle)
                    return true;
            }
        }

        stack[node] = false;
        return false;
    }

    bool IsCyclic()
    {
        bool *visited = new bool [v];
        bool *stack = new bool[v];

        return cycleHelp(0,visited,stack);
    }

};

int main(int argc, char const *argv[]) {
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(2,3);
    if(!g.IsCyclic())
        cout<<"Is A Tree"<<endl;
    else
        cout<<"Cyclic graph"<<endl;
    return 0;
}
