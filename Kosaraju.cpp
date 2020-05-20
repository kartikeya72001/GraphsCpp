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
        //cout<<"Cur from dfshelper "<<cur<<"\n";
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
    void printorder()
    {
        for(int i=0;i<order.size();i++)
            cout<<i<<" ";
        cout<<endl;
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
    //g.printorder();
    g.dfsreverse(n);
    g.print(n);
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

/*
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
class Graph{
public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        k[y].push_back(x);
    }

    void dfshelper(int cur,vector<bool> &vis,vector<int>&ans)
    {
        vis[cur] = 1;
        for(auto x:l[cur])
        {
            if(!vis[x])
                dfshelper(x,vis,ans);
        }
        ans.push_back(cur);
    }

    vector<int> dfs(int n)
    {
        vector<bool> vis(n+1,0);
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                dfshelper(i,vis,ans);
        }

        return ans;
    }

    void dfshelperReverse(int cur, vector<bool>&vis)
    {
        vis[cur] = 1;
        cout<<cur<<" ";
        for(auto x:k[cur])
        {
            if(!vis[x])
                dfshelperReverse(x,vis);
        }
    }

    void dfsreverse(int n)
    {
        int count=0;
        vector<int> ans2=dfs(n);
        vector<bool> vis2(n+1,false);
        for(int i=n-1;i>=0;i--)
        {
            if(!vis2[ans2[i]])
            {
                dfshelperReverse(ans2[i],vis2);
                count++;
                cout<<endl;
            }
        }

        cout<<count;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    Graph g;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.dfsreverse(n);
    return 0;
}
*/
