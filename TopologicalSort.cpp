#include <iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        //l[y].push_back(x);
    }
    void dfshelper(T src, map<T,bool> &visited, list<T> &order){
        visited[src] = true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfshelper(nbr,visited,order);
            }
        }

        order.push_front(src);
        return;
    }
    void dfs()
    {
        map<T,bool> visited;
        list<T> order;
        for(auto x:l){
            T node = x.first;
            visited[node] = false;
        }

        //Iterating all over
        for(auto p:l)
        {
            T node = p.first;
            if(!visited[node]){
                dfshelper(node,visited,order);
            }
        }
        for(T node:order)
        {
            cout<<node<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph<string> g;
    g.addEdge("Operating System","Internet");
    g.addEdge("Router","Internet");
    g.addEdge("Internet","Coding Blocks");
    g.addEdge("Coding Blocks","Coding");
    g.addEdge("IDE","Coding");

    g.addEdge("Internet","IDE");
    g.addEdge("Brain","Router");
    // g.addEdge(5,3);
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(1,7);
    // g.addEdge(2,7);
    // g.addEdge(4,7);
    // g.addEdge(4,9);
    // g.addEdge(4,8);
    // g.addEdge(6,8);
    // g.addEdge(5,6);
    // g.addEdge(3,2);
    // g.addEdge(7,9);
    // g.addEdge(8,9);
    // g.addEdge(3,4);

    g.dfs();
    return 0;
}
