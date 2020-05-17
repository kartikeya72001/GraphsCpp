#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU{
public:
    vector<int> par;
    int totalcom = 0;
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
            par[supy] = supx;
            totalcom--;
        }
    }
    int Components()
    {
        return totalcom;
    }
    unordered_map<int,int> Pairing(int n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[par[i]]++;
        return mp;
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    DSU d(n);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        d.Merge(a,b);
    }

    unordered_map<int,int> freq = d.Pairing(n);
    int sum = 0;
    for(auto itr:freq)
        sum += itr.second*(n-itr.second);
    cout<<sum/2<<endl;
    return 0;
}
