// Introduction to graphs 
#include <stdio.h> 
#include <stdlib.h> 

struct AdjListNode{
	int dest;
	struct AdjListNode* next; 
};

struct AdjList
{
	/* data */
	struct AdjListNode *head; //Pointer to the head node
};

struct Graph
{
	/* data */
	int v;
	struct AdjList* array; //struct to represent an adjacency list - array of adjacency lists of 
	// size V -< number of vertices in graph.
};

//utility function to create a new adjacency list node 

struct AdjListNode* newAdjListNode(int dest)
{
	/* data */
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest; 
	newNode->next = NULL;
	return newNode;
};

struct Graph* createGraph(int v)
{
	/* data */
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph -> v = v;
	// Creating an array of adjacency lists. size of each array will be V
	graph ->array = (struct AdjList*) malloc(v * sizeof(struct AdjList));
	// Intitializing each array head to NULL
	for (int i=0;i<v;++i){
		graph->array[i].head = NULL;
	}
	return graph;
};

// Adds and edge to the graph thus created 

void addEdge(struct Graph* graph, int src, int dest){

	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph -> array[src].head;
	graph->array[src].head = newNode; 

	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph -> array[dest].head = newNode; 
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->v; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}