// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
    int V;

    list<pair<int, int>> *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{

    priority_queue<iPair, vector<iPair>, greater<iPair>>
        pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver's code
int main()
{
    int V = 5 ;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, -1);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, -2);
    g.addEdge(1, 4, 6);

    // Function call
    g.shortestPath(0);

    return 0;
}
