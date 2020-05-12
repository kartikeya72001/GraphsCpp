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
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool IsCyclic()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];
        queue<int> q;


        for(int i=0;i<v;i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int nbr:l[node])
            {
                if(visited[nbr]==true && parent[node]!=nbr)
                    return false;
                else if(!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }

};

int main(int argc, char const *argv[]) {
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(0,1);
    g.addEdge(2,3);
    if(g.IsCyclic())
        cout<<"Is A Tree"<<endl;
    else
        cout<<"Cyclic graph"<<endl;
    return 0;
}
