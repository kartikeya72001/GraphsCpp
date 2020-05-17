#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

int dfs(vector<vector<int>>&graph,int src,vector<bool>&vis)
{
    vis[src]=true;
    int count=0;

    for(int e:graph[src])
        if(vis[e]==false)
            count+=dfs(graph,e,vis);

    return count+1;
}

ll gcc(vector<vector<int>>&graph)
{
    vector<bool> vis(graph.size(),false);
    vector<int> comps;

    for(int i=0;i<graph.size();i++)
    {
        if(vis[i]==false)
        {
            int compsize=dfs(graph,i,vis);
            comps.push_back(compsize);
        }
    }

    ll total=(graph.size()*(graph.size()-1))/2;
    for(int i=0;i<comps.size();i++)
    {
        if(comps[i]==1)
            continue;

        total-=((comps[i]*(comps[i]-1))/2);
    }

    return total;
}

int main(int argc,char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>());

    for(int i=0;i<e;i++)
    {
        int st,en;
        cin>>st>>en;
        graph[st].push_back(en);
        graph[en].push_back(st);
    }

    cout<<gcc(graph);
}
