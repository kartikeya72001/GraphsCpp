#include <iostream>
#include<queue>
#include<map>
#include<list>

using namespace std;

class Graph{
    list<int> *l;
    int v;
public:
    Graph(int v){
        this->v = v;
        this->l = new list<int>[v];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void topological(){
        int *indeg = new int[v];
        for(int i=0;i<v;i++){
            indeg[i] = 0;
        }
        for(int i=0;i<v;i++){
            for(auto y:l[i]){
                indeg[y]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:l[node]){
                indeg[nbr]--;
                if(indeg[nbr]==0)
                    q.push(nbr);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.topological();
    return 0;
}
