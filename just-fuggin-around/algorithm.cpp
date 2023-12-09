#include <bits/stdc++.h>
using namespace std;

vector<int> Djikstra(vector<pair<int, int>> Graph[], int Nodes, int SRC_NODE)
{

	vector<int> DISTANCE(Nodes + 1, 1e5);
	DISTANCE[SRC_NODE] = 0;

	// Min Heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push(make_pair(SRC_NODE, 0));

	while (!Q.empty())
	{
		cout << "Processing" << endl;
		int CURR_NODE = Q.top().first;
		int NODE_DIST = Q.top().second;
		Q.pop();
		for (auto CONNECTED_NODES : Graph[CURR_NODE])
		{
			int ADJ_NODE = CONNECTED_NODES.first;
			int ADJ_NODE_WT = CONNECTED_NODES.second;

			if (ADJ_NODE_WT + NODE_DIST < DISTANCE[ADJ_NODE])
			{
				DISTANCE[ADJ_NODE] = ADJ_NODE_WT + NODE_DIST;
				Q.push(make_pair(DISTANCE[ADJ_NODE], ADJ_NODE));
			}
		}
		for (auto it : DISTANCE)
		cout << it << " ";
	cout << endl;

	}

	return DISTANCE;
}

int main()
{

	int Edges, Nodes;
	cin >> Edges >> Nodes;

	vector<pair<int, int>> Graph[Nodes];

	for (int i = 0; i < Edges; i++)
	{
		int SRC, DEST, wt;
		cin >> SRC >> DEST >> wt;
		Graph[SRC].push_back(make_pair(wt, DEST));
		cout << "OK" << endl;
	}

	Djikstra(Graph, Nodes, 0);

	return 0;

}
