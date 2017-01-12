/*
Karan Chawla
Algorithm: Dijkstra's Shortest path Algorithm
Time Complexity: O(V^2)
Doesn't work for negative edges
*/

//Using matrix representaiton of graphs

#include "stdio.h"
#include <stdlib.h>
#include <limits.h> 

#ifndef V
#define V 9
#endif

//utility funciton to find the vertex with min distance
//value from the set of vertices not yet included in shortest path tree
int minDistance(int *dist, int sptSet[])
{
	int min = INT_MAX;
	int min_index;

	for( int v=0; v<V; v++)
	{
		if(sptSet[v]==0 && dist[v]<= min)
		{
			min = dist[v];
			min_index = v;
		}
	}

	return min_index;
}

//utility function to print the distance array
void printSolution(int dist[], int n)
{
	printf("Vertex \t Distance from Source\n");
	for(int i=0;i<n;i++)
	{
		
		printf("%d \t \t \t %d\n", i,dist[i]);
	} 
}

//implements Dijkstra for a graph represented as VxV matrix 
//Computes shortest path with src as the starting node
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; //dist[i] = shortest ditance from src to i
 
	int sptSet[V]; // 1 if vertex is included in shortes path else 0

	for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V-1; count++)
    {
    	int minVertex = minDistance(dist,sptSet);

    	sptSet[minVertex] = 1;

    	for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[minVertex][v] && dist[minVertex]+graph[minVertex][v] < dist[v])
            dist[v] = dist[minVertex] + graph[minVertex][v];
    }
    printSolution(dist,V);
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}