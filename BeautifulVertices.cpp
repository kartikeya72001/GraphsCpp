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
