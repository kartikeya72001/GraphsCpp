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
    void addEdge(int x, int y, bool bi = false){
        l[x].push_back(y);
        if(bi)
            l[y].push_back(x);
    }

    bool cycleHelp(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for(auto nbr:l[node])
        {
            if(!visited[nbr])
            {
                bool cycle = cycleHelp(nbr,visited,node);
                if(cycle)
                    return true;
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }

    bool IsCyclic()
    {
        bool *visited = new bool[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
        }

        return cycleHelp(0,visited,-1);
    }

};

int main(int argc, char const *argv[]) {
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.addEdge(0,1);
    g.addEdge(2,3);
    if(!g.IsCyclic())
        cout<<"Is not cyclic"<<endl;
    else
        cout<<"Cyclic graph"<<endl;
    return 0;
}
