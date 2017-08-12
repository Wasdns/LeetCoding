// Dijkstra Review, 2017.8, Wasdns
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// define max number is 10000
#define MAXN 10000

// Note that both the width and length are began with 1
int G[MAXN][MAXN];

// the results
int dijResult[MAXN];

// searched points
bool isSearched[MAXN];

// initializeGraph: using it to initialize the graph
void initializeGraph(int graphScale) {
	int i, j;
	for (i = 0; i <= graphScale; i++) {
		// initialize the global set
		isSearched[i] = false;
		dijResult[i] = MAXN;

		// initialize the graph
		for (j = 0; j <= graphScale; j++) {
			G[i][j] = MAXN;
		}
	}
}

// printGraph: using it to print the graph
void printGraph(int graphScale) {
	int i, j;

	printf("The graph is presented in terms of a set:\n");
	for (i = 0; i <= graphScale; i++) {
		for (j = 0; j <= graphScale; j++) {
			if (j == graphScale) {
				printf("%d\n", G[i][j]);
			} else {
				printf("%d ", G[i][j]);
			}
		}
	}
}

// dijkstra mechanism
int dijkstra(int graphScale, int src, int dst) {
	int i, j;

	// first tag the source point as searched. 
	isSearched[src] = true;

	// loop
	dijResult[src] = 0;

	while(true) {
		// break condition: if not using dijkstra, break.
		bool dijkstraApplied = false;

		// joined point: be tagged as being searched.
		int joinedPoint = -1;

		// edge with min length
		// Note: minvalue is the length between current node and source node
		int minsrc = MAXN, mindst = MAXN, minlength = MAXN, minvalue = MAXN;

		for (i = 1; i <= graphScale; i++) {
			// pass unsearched points
			if (!isSearched[i]) {
				// still have untagged point
				dijkstraApplied = true;
				continue;
			}

			// find the min length of current point
			// Note: tempvalue is the length between current node and source node
			int tempsrc = MAXN, tempdst = MAXN, templength = MAXN, tempvalue = MAXN;
			for (j = 1; j <= graphScale; j++) {
				// pass edges which have being passed
				if (isSearched[j]) continue;

				// update min length of current point
				if (dijResult[i]+G[i][j] < tempvalue) {
					tempsrc = i;
					tempdst = j;
					templength = G[i][j];
					tempvalue = dijResult[i]+G[i][j];
				}
			}

			// if the temp min length < min length, do update
			if (tempvalue < minvalue) {
				minsrc = tempsrc;
				mindst = tempdst;
				minlength = templength;
				minvalue = tempvalue;

				// debug
				// printf("p%d %d %d %d %d\n", i, minsrc, mindst, minlength, minvalue);

				joinedPoint = tempdst;
			}
		}

		// debug
		// printf("finished: %d %d %d %d\n", minsrc, mindst, minlength, minvalue);

		// tagged the point as being searched.
		if (joinedPoint != -1) {
			// joined the point and update the result 
			isSearched[joinedPoint] = true;
			dijResult[mindst] = dijResult[minsrc]+minlength;
		}

		// if not using dijkstra, break.
		if (!dijkstraApplied) break;
	}

	return dijResult[dst];
}

int main() {
	int i, j;
	int graphScale;
	int edgeNumber;

	// input scale of the graph
	printf("graphScale: ");
	scanf("%d", &graphScale);

	// initialize the graph with the graph scale
	initializeGraph(graphScale);

	// input edges
	printf("edgeNumber: ");
	scanf("%d", &edgeNumber);

	printf("edges(format: src dst value):\n");
	int src, dst, value; 
	// input edges and their values
	for (i = 0; i < edgeNumber; i++) { 
		scanf("%d%d%d", &src, &dst, &value);

		// initialize the graph
		G[src][dst] = value;
		G[dst][src] = value;
	}

	// print graph
	printGraph(graphScale);

	// input source and destination
	int dijsrc, dijdst, minlength;
	scanf("%d%d", &dijsrc, &dijdst);

	// calculate min length by using dijkstra mechanism
	minlength = dijkstra(graphScale, dijsrc, dijdst);
	printf("The min length from point %d to point %d is %d.\n", dijsrc, dijdst, minlength);

	return 0;
}