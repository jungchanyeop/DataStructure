#include <stdio.h>
#include <stdlib.h>
#include "adjList.h"

void createGraph(graphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;
}

void insertVertex(graphType* g, int v) {
	if (g->n + 1 > MAX_VERTEX) {
		printf("\n 정점 개수 초과");
		return ;
	}

	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점");
		return;
	}

	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjMatrix(graphType* g) {
	graphNode* p;
	for (int i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}