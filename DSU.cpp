#include <iostream>
#include <vector>
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
    int n;
    cout<<"Enter Size"<<endl;
    cin>>n;
    DSU d(n);
    d.Merge(1,2);
    d.Merge(2,3);
    cout<<d.Components();
    return 0;
}
