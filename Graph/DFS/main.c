#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

int main() {

	graphType* G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);

	for (int i = 0; i < 7; i++)
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1); // 1
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3); // 2
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0); 
	insertEdge(G9, 3, 6); // 3
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2); // 5, 6
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6); // 7
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4); // 4
	insertEdge(G9, 6, 3);
	printf("\n G9�� ���� ����Ʈ ");
	print_adjList(G9);

	printf("\n\n ���� �켱 Ž�� >>");
	DFS_adjList(G9, 0);

	return 0;
}