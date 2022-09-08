#include <iostream>
using namespace std;

class Graph {
	int V;
	vector<vector<int>> l;
public:
	Graph (int V) {
		this->V = V;
	}

	void addEdge(int u, int v, int wt, bool undir = true) {
		l[u].push_back({ wt, v });
		if (undir) {
			l[v].push_back({ wt, u });
		}
	}

	int djikstra (int src, int dest) {

		// ds
		vector<int> dist(V, INT_MAX);
		set <pair<int, int> > s;

		// init
		dist[src] = 0;
		s,insert({ 0, src }); // distance and sorc node

		while (!s.empty()) {
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first;
			s.erase(it);

			// iterate over nbrs
			for (auto &nbrPair : l[node]) {
				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;

				if (currentEdge + distTillNow < dist[nbr]) {
					// remove if nbr already exists
					auto f = s.find({ dist[nbr], nbr });
					if (f != s.end()) {
						s.erase(f);
					}

					dist[nbr] = distTillNow + currentEdge;
					s,insert({ dist[nbr], nbr });
				}
			}
		}

		// sssp
		for (int i = 0; i < V; ++i) {
			
		}

		// return 
		return dist[dest];
	}
}