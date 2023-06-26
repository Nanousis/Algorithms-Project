// Panagiotis Nanousis 2023
// Giannis Giannoulas
// Orestis Panopoulos
#include "functions.h"


/*
    On this file we have the functions that are used
    to print our arrays, nodes and vertexes for debugging
    purposes.
*/

//prints the connections of a vertex
void PrintVertex(vertex vert, int vertNum){
    int i=0;
    printf("Connection %d is connected to:\n",vertNum);
    for(i=0;i<vert.numberOfConnections;i++){
        printf("%d.)  %d -> %d\n",i+1,vertNum,vert.connections[i]);
    }
}
//prints the connections. Used for debugging.
void PrintConnections(vertex *vertices, int numbOfVertices){
    int i=0;
    for(i=0;i<numbOfVertices;i++){
       PrintVertex(vertices[i],i);
    }
}

void printDistanceMatrix(int *dist,int numbOfVertices)
{
    int i,j,sum;
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (i = 0; i < numbOfVertices; i++) {
        printf("%d.) ",i);
            sum=0;
        for (j = 1; j < numbOfVertices; j++) {
            if(i==0){
                printf("%6d!",j);
                continue;
            }
            if (dist[i*numbOfVertices + j] == INF)
                printf("%7s", "INF");
            else{
                printf("%7d", dist[i*numbOfVertices + j]);
                sum+=dist[i*numbOfVertices + j];
            }
        }
        printf(" sum is %d\n",sum);
    }
}
//prints a nodeCount array
void PrintNodeSorted(NodeCount *array, int start, int size ,int maxNum){
    int i, num_runtimes=((size>maxNum)?maxNum:size), num=(start)?-1:0;
    for(i=start; i<num_runtimes; i++) {
        printf("%3d.)Node %3d is in %3d\n", i+num+1, array[i].index, array[i].count);
        
    }
}
