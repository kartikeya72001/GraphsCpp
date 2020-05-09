#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addEdge(string x, string y, bool bi,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bi)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }
    void PrintList()
    {
        for(auto p:l)
        {
            string city = p.first;
            list<pair<string,int>> nbr = p.second;
            cout<<"City: "<<city<<"->";
            for(auto nbrs:nbr)
            {
                string dest = nbrs.first;
                int dist = nbrs.second;

                cout<<dest<<" "<<dist<<",";
            }
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph g;
    g.addEdge("A","B",true,10);
    g.addEdge("C","A",true,15);
    g.addEdge("A","D",false,12);
    g.addEdge("C","B",true,9);
    g.PrintList();
    return 0;
}
