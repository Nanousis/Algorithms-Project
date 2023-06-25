#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char *argv[]) {

    clock_t start, end;
    double execution_time, minutes;
    NodeRanking *in_rankingsPtr;

    start = clock();
    if (argc != 2) {
        printf("You should run this ./%s filename", argv[0]);
        return 1; // Indicate an error by returning a non-zero value
    }
    // Read the file
    char *filename = argv[1];
    int numberOfVertices=GetNumOfVertices(filename)+1;
    if(numberOfVertices<=0+1){
        printf("Error reading the file: %s\n", filename);
        return 1; // Indicate an error by returning a non-zero value
    }

    FILE *networkFile = fopen(filename, "r");
    if (networkFile == null) {
        printf("Error opening the file: %s\n", filename);
        return 1; // Indicate an error by returning a non-zero value
    }
    
    vertex *vertices=InitializeVertices(numberOfVertices,networkFile);
    if(vertices==null){
        printf("Something went wrong trying to read the network\nTotal vertices %d\n",numberOfVertices);
        return -1;
    }

    int *Next;
    int *floyDistance;
    //calculate the FloydWarshall APSP matrix and the next node for each shortest path
    //floyDistance[i][j] shows the distance from i to j
    //Next[i][j]=k shows the first node of the shortest path then next[k][j]
    //untill you reach your destination
    floyDistance = FloydWarshall(vertices,numberOfVertices,&Next);
    if (!floyDistance||!Next) return -1;
    printDistanceMatrix(Next,numberOfVertices);
    //sorts the next based on how many times a node is included in all shortest paths
    NodeCount *betweennessSorted=GetSortedBetweennessCentrality(Next,numberOfVertices,true);
    //sorts the floyDistance based on the distance to all nodes
    NodeCount *closenessSorted=GetSortedClosenessCentrality(floyDistance,numberOfVertices,true);

    printf("The betweenness array is (bigger is better):\n");
    PrintNodeSorted(betweennessSorted, numberOfVertices-1);

    printf("The closeness array is (total distance)(smaller is better):\n");
    PrintNodeSorted(closenessSorted, numberOfVertices-1);

    printf("Total number of vertices: %d\n",numberOfVertices-1);

    in_rankingsPtr = GetRankingsOfAll(betweennessSorted, closenessSorted, numberOfVertices);
    printf("\nKendall coefficient is: %.3lf\n", kendal(in_rankingsPtr->rankA, in_rankingsPtr->rankB, numberOfVertices));
    end = clock();

    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    minutes=execution_time/60;
    printf("\nTime taken is %02.2lf minutes / %02lf seconds",minutes,execution_time);

    FreeVertices(vertices,numberOfVertices);
    free_rankings(in_rankingsPtr);
    free(Next);
    free(floyDistance);
    free(betweennessSorted);
    free(closenessSorted);
    free(vertices);
    fclose(networkFile); // Close the file when done
    return 0;
