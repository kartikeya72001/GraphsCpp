#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;
public:
    void addEdge(T u, T v, int dist, bool bi = false)
    {
        m[u].push_back(make_pair(v,dist));
        if(bi)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }

    void Print()
    {
        for(auto j:m)
        {
            cout<<j.first<<" --> ";
            for(auto l:j.second)
            {
                cout<<l.first<<"("<<l.second<<") ";
            }
            cout<<endl;
        }
    }

    void Dijkstra(T src)
    {
        unordered_map<T,int> dist;
        for(auto j:m)
        {
            dist[j.first] = INT_MAX;
        }

        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto child:m[node])
            {
                if(nodeDist + child.second < dist[child.first])
                {
                    T dest = child.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist+child.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist)
        {
            cout<<d.first<<" is located at a Distance of: "<<d.second<<" from "<<src<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph<string> g;
    g.addEdge("Delhi","Jaipur",300);
    g.addEdge("Delhi","Mumbai",1200);
    g.addEdge("Mumbai","Jaipur",700);
    g.addEdge("Delhi","Mt. Abu",800);
    g.addEdge("Mt. Abu","Jaipur",500);

    g.Print();
    cout<<endl;
    g.Dijkstra("Delhi");
    return 0;
}
