#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
    vector<int> par;
    int totalcom = 0;

public:
    DSU(int n)
    {
        totalcom = n;
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i] = i;
        }
    }
    int getSupPar(int x)
    {
        if(x==par[x])
            return x;
        else{
            //Path Compression
            return par[x] = getSupPar(par[x]);
        }
    }

    void Merge(int x, int y)
    {
        int supx = getSupPar(x);
        int supy = getSupPar(y);
        if(supx!=supy)
        {
            par[supx] = supy;
            totalcom--;
        }
    }
    int Components()
    {
        return totalcom;
    }
};

int main(int argc, char const *argv[]) {
    int n,m,ans=0;
    //cout<<"Enter Size"<<endl;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        //x--;y--;w--;
        edges[i] = {w,x,y};
    }
    sort(edges.begin(),edges.end());
    DSU d(n);

    for(int i=0;i<m;i++)
    {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];
        //cout<<w<<" "<<x<<" "<<y<<endl;
        if(d.getSupPar(x) != d.getSupPar(y))
        {
            d.Merge(x,y);
            ans+=w;
        }
    }
    cout<<ans;
    return 0;
}
/*
    7 8
    0 1 1
    1 2 4
    1 4 2
    2 3 4
    3 4 3
    4 5 5
    5 6 2
    6 0 3
*/
