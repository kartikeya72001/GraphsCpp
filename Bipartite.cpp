#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
bool odd_cycle = 0;
class Graph{
    map<int,list<int>> l;
    vector<int> visited;
public:
    Graph(int m)
    {
        visited.resize(m+1);
    }
    
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bipartite(int cur, int par, int col)
    {
        visited[cur] = col;
        for(auto child:l[cur])
        {
            if(visited[child]==0)
                bipartite(child,cur,3-col);
            else if(child != par && col==visited[child])
            {
                odd_cycle = 1;
                return;
            }
        }
        return;
    }
};

int main(int argc, char const *argv[]) {
    int n,m;
    cin>>n>>m;
    Graph g(m);
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.bipartite(1,0,1);
    if(odd_cycle)
        cout<<"Not a Bipartite Graph"<<endl;
    else
        cout<<"Bipartite Graph"<<endl;
    return 0;
}
