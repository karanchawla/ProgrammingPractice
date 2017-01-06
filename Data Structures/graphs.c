/*
Karan Chawla
Data Structure: Graphs
*/

#include <stdio.h> 
#include <stdlib.h> 

//Representation of an undirected graph using adjacency lists

struct node
{
	int dest;
	struct node* next;
};

struct list
{
	struct node* head;
};

//array of adjacency lists
//size of array: v which is the vertices in the graph
struct Graph
{
	int v;
	struct list* array;
};


//utility function to create a new node
struct node* newAdjNode(int dest)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

//utility function to create a graph of v vertices
struct Graph* createGraph(int v)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->v = v;

	//create array of adjacency lists with each size as v
	graph->array = (struct list*) malloc(v * sizeof(list));

	int i=0;
	for(int i=0;i<v;i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{

    struct node* newNode = newAdjNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
	int i;
	for(i=0;i<graph->v;++i)
	{
		struct node* temp = graph->array[i].head;
		printf("%d ", i);
		while(temp)
		{
			printf(" -> %d ", temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
    int V = 5;
 
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    printGraph(graph);
 
    return 0;
}