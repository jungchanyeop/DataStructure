#include <stdio.h>
#include "dijkstra.h"

int main(){
	extern int weight[MAX_VERTICES][MAX_VERTICES];

	printf("\n ********** 가중치 인접 행렬 **********\n\n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n");
	}

	printf("\n ********** 다익스트라 최단 경로 구하기 **********\n");
	Dijkstra_shortestPath(1, MAX_VERTICES);

	return 0;
}