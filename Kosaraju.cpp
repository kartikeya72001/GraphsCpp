#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
class Graph{
    map<int,list<int>> l,k;
    vector<bool> visited;
    vector<int> order;
    vector<int> comp;
public:
    Graph(int n){
        order.resize(n+1);
        visited.resize(n+1);
        comp.resize(n+1);
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        k[y].push_back(x);
    }

    void dfshelper(int cur)
    {
        visited[cur] = true;
        for(auto x : l[cur])
        {
            if(!visited[x])
            {
                //cout<<"X: "<<x<<endl;
                dfshelper(x);
            }
        }
        order.push_back(cur);
    }

    void dfs(int n)
    {
        for(int i=1;i<=n;i++){
            if(!visited[i])
            dfshelper(i);
        }
    }

    void dfshelperReverse(int cur, int col)
    {
        comp[cur] = col;
        visited[cur] = true;
        for(auto x : k[cur])
        {
            if(!visited[x])
            dfshelperReverse(x,col);
        }
    }

    void dfsreverse(int n)
    {
        int col = 1;
        for(int i=n;i>=1;i--)
        {
            if(!visited[order[i]])
            {
                dfshelperReverse(order[i],col);
                col++;
            }
        }
    }
    void emptyvisited()
    {
        for(int i=0;i<visited.size();i++)
        visited[i]=false;
        return;
    }
    void print(int n){
        for(int i=1;i<=n;i++){
            cout<<i<<" -> "<<comp[i]<<endl;
        }
        return;
    }
    void printG(int n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" -> ";
            for(auto x: l[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    Graph g(n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.dfs(n);
    g.emptyvisited();
    g.dfsreverse(n);
    g.print(n);
    //g.printG(n);
    return 0;
}
/*
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4
*/
