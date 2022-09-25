// given a weighted, undirected, connected graph, find a mst
// Prim's algorithm
// greedy approach
// Naive using adj matrix

int primMST (vector<int> graph, int v) {
	int key[v], res = 0;
	fill (key, key + v, INT_MAX);
	key[0] = 0;
	bool mset[v] = {false};

	for (int count = 0; count < v; ++count) {
		int u = -1;

		// find minimum node
		for (int i = 0; i < v; ++i) 
			if (!mset[i] && (u == -1 || key[i] < key[u]))
				u = i;

		mset[u] = true;
		res += key[u];

		for (int flag = 0; flag < v; ++flag) {
			if (graph[u][v] != 0 && mset[v] == false)
				key[v] = min(key[v], graph[u][v]);
		}

		
	}
}