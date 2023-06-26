// Panagiotis Nanousis 2023
// Giannis Giannoulas
// Orestis Panopoulos


#ifndef FUNCTIONS
#define FUNCTIONS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define null ((void *)0)
#define INT16_MAX 1000000000
#define INF INT16_MAX*2
#define true 1
#define false 0

typedef struct vertex{
    int numberOfConnections;
    int *connections;    
}vertex;
typedef struct NodeCount{
    int index;
    int count;
} NodeCount;

typedef struct nodeRanking{
    int* rankA;
    int* rankB;
} NodeRanking;

//gets the id of the biggest vertex
extern int GetNumOfVertices(char * filename);
//initializes the vertices
extern vertex *InitializeVertices(int numberOfVertices,FILE *file);
//adds a connection to a vertex
extern void AddConnection(vertex *vertices,int vertex1, int vertex2);
//prints the connections of a selected vertex
extern void PrintVertex(vertex vert, int vertNum);
//prints all the connections of the network
extern void PrintConnections(vertex *vertices, int numbOfVertices);
extern void printDistanceMatrix(int *dist,int numbOfVertices);
//frees memory
extern int FreeVertices(vertex *vertices, int numbOfVertices);

extern int *FloydWarshall(vertex *vertices, int numbOfVertices,int **NextConnection);

extern NodeCount *GetSortedClosenessCentrality(int *dist,int numbOfVertices,int boolSort);
extern NodeCount *GetSortedBetweennessCentrality(int *Next,int numbOfVertices,int boolSort);

void PrintNodeSorted(NodeCount *array, int start, int size, int maxNum);

extern NodeRanking *GetRankingsOfAll(NodeCount *array1, NodeCount *array2,int size);
#define sign(x) ((x>0) - (x<0))
double kendal ( NodeRanking* rankPtr, const int size );
void free_rankings ( NodeRanking* rankPtr);

#endif
