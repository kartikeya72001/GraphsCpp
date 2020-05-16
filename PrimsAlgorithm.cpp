#include <iostream>
#include <list>
#include <climits>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *l;
public:
    Graph(int v)
    {
        this->v = v;
        l = new list<pair<int,int>> [v];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }

    int findMinVertex(int *wt, bool* visited, int v)
    {
        int minvertex = -1;
        for(int i=0;i<v;i++)
        {
            if(!visited[i] && (minvertex==-1 || wt[i]<wt[minvertex]))
            {
                minvertex = i;
            }
        }
        return minvertex;
    }

    void PrimsAlgo()
    {
        bool * visited = new bool [v];
        int  *parent = new int [v];
        int *wt = new int [v];

        for(int i=0;i<v;i++)
        {
            visited[i] = false;
            wt[i] = INT_MAX;
        }
        parent[0] = -1;
        wt[0] = 0;
        for(int i=0;i<v;i++)
        {
            int minvertex = findMinVertex(wt,visited,v);
            visited[minvertex] = true;
            for(auto nbr:l[minvertex])
            {
                if(!visited[nbr.first])
                {
                    if(wt[nbr.first]>nbr.second)
                    {
                        parent[nbr.first] = minvertex;
                        wt[nbr.first] = nbr.second;
                    }
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-->"<<parent[i]<<" weight: "<<wt[i]<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    int n,e;
    cin>>n>>e;
    Graph g(n);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.PrimsAlgo();
    return 0;
}
/*
7 8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
*/
