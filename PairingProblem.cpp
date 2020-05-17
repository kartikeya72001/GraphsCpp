/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.
*/
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
