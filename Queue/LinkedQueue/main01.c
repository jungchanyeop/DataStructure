#include <stdio.h>
#include "LinkedQueue.h"

int main() {

	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ***** ���� ť ���� ***** \n");

	printf("\n ���� A>>");
	enLQueue(LQ, 'A');
	printLQ(LQ);

	printf("\n ���� B>>");
	enLQueue(LQ, 'B');
	printLQ(LQ);

	printf("\n ���� C>>");
	enLQueue(LQ, 'C');
	printLQ(LQ);

	data = peekLQ(LQ);
	printf("peek item : %c \n", data);

	printf("\n ���� >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n ���� >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n ���� >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n ���� D>>");
	enLQueue(LQ, 'D');
	printLQ(LQ);

	printf("\n ���� E>>");
	enLQueue(LQ, 'E');
	printLQ(LQ);

	return 0;
}