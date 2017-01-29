//Karan Chawla
//Tries to find the shortest path using DFS

#include <iostream>
#include <list>
#include <limits.h>
#include <algorithm>

using namespace std;

class Graph
{
private:
	int V; //number of vertices in the graph
	list<int> *adj; //pointer to an array of adjacency lists
	void ifVisited(int v, bool visited[]); //, int &level, int *dist
										   //utility function used by DFS because graphs can be cyclic
										  //so maintain a list of visited nodes
public:
	Graph(int V);
	void addEdge(int v, int w); //utility function to add an edge to the graph
	void DFS();
	//void shortestPath(int start, int end);
};

typedef struct node
{
	int key;
	int weight;
}Node;

//constructor
/*Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V]; //I don't like Heap memory but well c'est la vie
}*/

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<Node>[V];
}

/*void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // add an edge to the graph
	//To Do:
	// Wrap w in a struct to add weights and int to the graph
}*/

void Graph::addEdge(int v, Node w)
{
	adj[v].push_back(w);
}

void Graph::ifVisited(int v, bool visited[]) //, int &level, int *dist
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i; //bjarne stroustrup says use iterators for speed
	for(i = adj[v].begin(); i!=adj[v].end(); ++i)
	{
		//int t = (int) *i;
		//if the vertex is not visited
		if( !visited[*i] ) //&& level + 1 < dist[*i]
		{
			//dist[*i] = level + 1;
			//ifVisited( *i, visited, level + 1, dist);
			ifVisited( *i, visited);
		}
	}
}

void Graph::DFS()
{
	bool *visited = new bool[V];
	//int dist[V];
	//int level = 0;
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;	
		//dist[i] = INT_MAX;
	}

	for(int i=0; i<V; i++)
	{
		if(visited[i]==false)
		{
			//ifVisited(i, visited, level, dist);
			ifVisited(i, visited);
		}
	}
//	cout << *min_element(dist,dist+V);
}


int main(void)
{
	Graph newGraph(7);
	newGraph.addEdge(0,1);
	newGraph.addEdge(0,2);
	newGraph.addEdge(1,4);
	newGraph.addEdge(1,3);
	newGraph.addEdge(3,5);
	newGraph.addEdge(4,5);
	newGraph.addEdge(5,6);
	newGraph.addEdge(2,6);

	/*
  			5
		  /	 \
	1 - 2	 6	
	 \	\	/ \
	  \	  4    \
	  3 ------ 7		

	*/


	newGraph.DFS();

	return 0;
}
