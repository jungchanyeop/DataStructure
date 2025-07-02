#include <stdio.h>
#include "floyd.h"

int main() {
	extern int weight[MAX_VERTICES][MAX_VERTICES];

	printf("\n ********** ����ġ ���� ��� **********\n\n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n");
	}

	printf("\n ********** �÷��̵� �ִ� ��� ���ϱ� **********\n");
	Floyd_shortestPath(MAX_VERTICES);

	return 0;
}