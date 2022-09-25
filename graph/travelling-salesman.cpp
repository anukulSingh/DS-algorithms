// hamiltonian cycle
// cycle covering all the nodes of the graph, and coming back to the same node
// output of travelling salesman prb is minimum weight hamiltonian cycle

#include <iostream>
using namespace std;
#define V 4

// we will iterate over all permutations of possible paths

// Naive way to get it
// O(fact(n)) TC
int travllingSalesmanProblem(int graph[][V], int s) {

	// store all vertex except spurce
	vector<int> vertex;
	for (int i = 0; i < V; ++i)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight hamiltonian cycle
	int min_path = INT_MAX;
	do {
		// store current path weight
		int current_pathweight = 0;
		// compute current path weight
		int k = s;
		for (int &x : vertex) {
			current_pathweight += graph[k][x];
			k = x;
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);
	} while (next_permutation(v.begin(), v.end()));

	return min_path;

}
// Driver Code
int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}