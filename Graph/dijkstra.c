#include <stdio.h>
#include "dijkstra.h"
#include "graphG.h"

int nextVertex(int n){
	int min, minPos;
	min = INF; // 최소 거리값을 무한대 값으로 초기화
	minPos = -1; // 정점이 선택되지 않음
	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

int printStep(int step){
	printf("\n %3d 단계 : S = {", step);
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (S[i] == TRUE)
			printf("%3c", i + 65);
	}

	if (step < 1)
		printf(" } \t\t\t");
	else if (step < 3)
		printf(" } \t\t");
	else
		printf(" } \t");
	printf(" distance :[ ");
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (distance[i] == INF)
			printf("%4c", '*');
		else
			printf("%4d", distance[i]);
	}
	printf("%4c", ']');
	return ++step;
}

void Dijkstra_shortestPath(int start, int n){
	int u, w, step = 0;
	for (int i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		S[i] = FALSE;
	}
	S[start] = TRUE;
	distance[start] = 0;
	step = printStep(0);
	for (int i = 0; i < n - 1; i++) {
		u = nextVertex(n);
		S[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!S[w]) {
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
			}
		}
		step = printStep(step);
	}
}