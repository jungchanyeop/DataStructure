#include <stdio.h>
#include "queueS.h"

int main() {
	QueueType* Q1 = createQueue();
	element data;

	printf("\n ***** ¼øÂ÷ Å¥ ¿¬»ê ***** \n");
	printf("\n »ðÀÔ A>>");
	enQueue(Q1, 'A');
	printQ(Q1);

	printf("\n »ðÀÔ B>>");
	enQueue(Q1, 'B');
	printQ(Q1);

	printf("\n »ðÀÔ C>>");
	enQueue(Q1, 'C');
	printQ(Q1);

	data = peekQ(Q1);
	printf(" peek item : %c \n", data);

	printf("\n »èÁ¦ >>");
	data = deQeue(Q1);
	printQ(Q1);

	printf("\n »èÁ¦ >>");
	data = deQeue(Q1);
	printQ(Q1);

	printf("\n »èÁ¦ >>");
	data = deQeue(Q1);
	printQ(Q1);

	printf("\n »ðÀÔ D>>");
	enQueue(Q1, 'D');
	printQ(Q1);

	printf("\n »ðÀÔ E>>");
	enQueue(Q1, 'E');
	printQ(Q1);

}