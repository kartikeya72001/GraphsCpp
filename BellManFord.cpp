#include <iostream>
#include <climits>
using namespace std;

class Edge{
public:
    int src, dest, weight;
};

class Graph{
public:
    int v, e;
    Edge *edge;
    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        edge = new Edge[e];
    }

    void addEdge(int u, int v, int w, int count)
    {
        edge[count].src = u;
        edge[count].dest = v;
        edge[count].weight = w;
    }

    void BellManFord(int src)
    {
        int distance[v];
        for(int i=0;i<v;i++)
        {
            if(i==src)
                distance[i] = 0;
            else
                distance[i] = INT_MAX;
        }

        //Relaxation
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;

                if(distance[src]!=INT_MAX and distance[src]+wt<distance[dest])
                {
                    distance[dest] = distance[src]+wt;
                }
            }
        }

        //Negative weight
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;

                if(distance[src]!=INT_MAX and distance[src]+wt<distance[dest])
                {
                    cout<<"Graph has negative Cycle"<<endl;
                    return;
                }
            }
        }

        for(int i=0;i<v;i++)
        {
            cout<<i<<" --> "<<distance[i]<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w,i);
    }
    g.BellManFord(0);
    return 0;
}
/*
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
*/
