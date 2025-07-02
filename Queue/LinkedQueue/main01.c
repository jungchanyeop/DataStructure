#include <stdio.h>
#include "LinkedQueue.h"

int main() {

	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ***** ¿¬°á Å¥ ¿¬»ê ***** \n");

	printf("\n »ðÀÔ A>>");
	enLQueue(LQ, 'A');
	printLQ(LQ);

	printf("\n »ðÀÔ B>>");
	enLQueue(LQ, 'B');
	printLQ(LQ);

	printf("\n »ðÀÔ C>>");
	enLQueue(LQ, 'C');
	printLQ(LQ);

	data = peekLQ(LQ);
	printf("peek item : %c \n", data);

	printf("\n »èÁ¦ >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n »èÁ¦ >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n »èÁ¦ >>");
	data = deLQueue(LQ);
	printLQ(LQ);

	printf("\n »ðÀÔ D>>");
	enLQueue(LQ, 'D');
	printLQ(LQ);

	printf("\n »ðÀÔ E>>");
	enLQueue(LQ, 'E');
	printLQ(LQ);

	return 0;
}