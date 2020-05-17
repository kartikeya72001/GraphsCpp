/*
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

Input Format
First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

Constraints
1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N

Output Format
Print the number of beautiful vertices in the graph.

Sample Input
4 3
1 2
2 3
2 4
Sample Output
1
Explanation
In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.
*/
#include <iostream>
#include <list>
#include <set>
#include <queue>
using namespace std;

class Graph{
public:
    int v;
    list<int> *adjl;
    list<int> *List;

    Graph(int v)
    {
        this->v = v;
        adjl = new list<int>[v];
        List = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    void findMaster()
    {
        set<int> s;
        for(int i=0;i<v;i++)
        {
            s.insert(i);
        }

        while(!s.empty())
        {
            bool *visited = new bool[v];
            for(int i=0;i<v;i++)
                visited[i] = false;

            auto itr = s.begin();

            queue<int> q;
            q.push(*itr);
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                visited[x] = true;
                s.erase(x);
                int size = adjl[x].size();
                for(int i=0;i<size;i++)
                {
                    int k = adjl[x].front();
                    adjl[x].pop_front();
                    if(!visited[k])
                    {
                        q.push(k);
                        List[x].push_back(k);
                    }
                }
            }
        }
        return;
    }
    int beautiful()
    {
		int child[v];
		int cnt = 0;

		for (int i = 0; i < v; i++)
            child[i] = List[i].size();

		for (int i = 0; i < v; i++)
        {
			int size = List[i].size();
			for (int k = 0; k < size; k++)
            {
				if (child[List[i].front()] > child[i] && child[i] != 0)
					cnt++;
				List[i].pop_front();
			}
		}
		return cnt;
	}
};

int main(int argc, char const *argv[]) {
    int n,m;
    cin>>n>>m;
    Graph g(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g.addEdge(u,v);
    }
    g.findMaster();
	cout << g.beautiful();
    return 0;
}
