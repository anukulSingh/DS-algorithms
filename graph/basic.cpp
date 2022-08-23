#include<bits/stdc++.h> 
using namespace std;

// covering the issue of disconnected graphs
void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

// count returns the no of components in the graph
int DFS(vector<int> adj[], int V){
    int count=0;
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {DFSRec(adj,i,visited);count++;}
    }
    return count;
}


// detect cycle in unndirected graph using dfs
// dfs recursion function
// checking for parent
bool DFSRec(vector<int> adj[], int s,bool visited[], int parent) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false){
            if(DFSRec(adj,u,visited,s)==true)
                {return true;}}
        else if(u!=parent)
            {return true;}
    }
    return false;
}


// detect cycle in directed graph
// if there is a back edge, there is a cycle
// TC O (v + e)
bool dfsRec (vector<int> adj[], int s, bool visited[], bool resSt[]) {
	visited[s] = true;
	resSt[s] = true; // everything set to false initially
	for (int &child: adj[s]) {
		if (!visited[child]) {
			if (dfsRec(adj, child, visited, resSt))
				return true;
			else if (resSt[child])
				return true;
		}
	}
	resSt[s] = false;
	return false;
}



// bfs based ques

// cycle detection in directed graph using bfs top sort (Kahn's algo)
bool isCycle(vector<int> adj[], int V) {
	vector<int> indegree(V, 0);
	for (int u = 0; u < V; ++u)
		for (int &x: adj[u])
			indegree[x]++;

	queue<int> q;
	int count = 0;
	for (int i = 0; i < V; ++i)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";

		for (int &x: adj[u]) {
			if (--indegree[x] == 0)
				q.push(x);
		}
		count++;
	}

	return (count != V);
}


// topological sorting (In Directed graphs)
void topSort(vector<int> adj[], int V) {
	vector<int> indegree(V, 0);
	for (int u = 0; u < V; ++u)
		for (int &x: adj[u])
			indegree[x]++;

	queue<int> q;
	for (int i = 0; i < V; ++i)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";

		for (int &x: adj[u]) {
			if (--indegree[x] == 0)
				q.push(x);
		}
	}
}



void BFS(vector<int> adj[], int s, bool visited[]) 
{ 	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 	 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

// covering the issue of disconnected graphs
void BFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            BFS(adj,i,visited);
    }
}



// shortest path to all other vertices from the source in an undirected graph
// using bfs
void BFS(vector<int> adj[], int V, int s,int dist[]) 
{ 
	bool visited[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	queue<int>  q;
	
	visited[s] = true;
	dist[s] = 0;
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        dist[v]=dist[u]+1;
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSDin(adj,V); 

	return 0; 
} 
