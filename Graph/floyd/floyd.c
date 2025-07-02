#include <stdio.h>
#include "floyd.h"
#include "graphG.h"

void printStep(int step) {
	printf("\n A%d : ", step);
	for (int i = 0; i < MAX_VERTICES; i++) {
		printf("\t");
		for (int j = 0; j < MAX_VERTICES; j++) {
			if (A[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", A[i][j]);
		}
		printf("\n\n");
	}
}

void Floyd_shortestPath(int n) {
	int step = -1;

	for (int v = 0; v < n; v++) {
		for (int w = 0; w < n; w++)
			A[v][w] = weight[v][w];
	}

	printStep(step);
	// v : 경유, v : 출발, w : 도착
	for (int k = 0; k < n; k++) {
		for (int v = 0; v < n; v++) {
			if (k == v)
				continue;
			for (int w = 0; w < n; w++) {
				if (k == w || v == w || A[k][w] == INF)
					continue;
				if (A[v][k] + A[k][w] < A[v][w])
					A[v][w] = A[v][k] + A[k][w];
			}
		}
		printStep(++step);
	}

}