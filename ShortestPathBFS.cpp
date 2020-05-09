#include <iostream>
#include<queue>
#include<map>
#include<list>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src) {
        map<T,int> dist;
        queue<T> q;

        for(auto node_pair:l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            //cout<<node<<" ";
            for(int nbr: l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }
            }

        }
        for(auto node_pair:l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<<" Distance: "<<d<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    return 0;
}
