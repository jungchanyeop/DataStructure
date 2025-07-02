#include "queueC.h"

int main() {

	QueueType* cQ = createCQueue();
	element data;
	printf("\n ***** ¿øÇü Å¥ ¿¬»ê ***** \n");
	
	printf("\n »ðÀÔ A>>");
	enCQueue(cQ, 'A');
	printCQ(cQ);

	printf("\n »ðÀÔ B>>");
	enCQueue(cQ, 'B');
	printCQ(cQ);

	printf("\n »ðÀÔ C>>");
	enCQueue(cQ, 'C');
	printCQ(cQ);

	data = peekCQ(cQ);
	printf(" peek item : %c \n", data);

	printf("\n »èÁ¦>>");
	data = deCQueue(cQ);
	printCQ(cQ);

	printf("\n »èÁ¦>>");
	data = deCQueue(cQ);
	printCQ(cQ);

	printf("\n »èÁ¦>>");
	data = deCQueue(cQ);
	printCQ(cQ);

	printf("\n »ðÀÔ D>>");
	enCQueue(cQ, 'D');
	printCQ(cQ);

	printf("\n »ðÀÔ E>>");
	enCQueue(cQ, 'E');
	printCQ(cQ);

	return 0;
}