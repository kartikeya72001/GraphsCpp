#include <iostream>
#include<climits>
#include<vector>
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph)
{
    int V = graph.size();
    vector<vector<int>> dist(graph);
    for (int k=0;k<V;k++){
        for (int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]> dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> graph = {
        {0,INT_MAX,-2,INT_MAX},
        {4,0,3,INT_MAX},
        {INT_MAX,INT_MAX,0,2},
        {INT_MAX,-1,INT_MAX,0}
    };
    auto result = floyd_warshall(graph);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result.size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
