#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v + 65);

	while (!isStackEmpty()) {
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				push(w->vertex);
//				printf("\tpush : %c\n", w->vertex + 65);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else // g->visited[w->vertex]가 이미 지나친 간선이면
				w = w->link;
		}
		v = pop(); 
//		printf("\tpop : %c\n", v + 65);
	}

}