#include "DeQue.h"

int main() {

	DQueType* DQ1 = createDQue();
	element data;

	printf("\n ***** ��ũ ���� ***** \n");
	
	printf("\n fornt���� A>> ");
	insertFront(DQ1, 'A');
	printDQ(DQ1);

	printf("\n fornt���� B>> ");
	insertFront(DQ1, 'B');
	printDQ(DQ1);

	printf("\n rear���� C>> ");
	insertRear(DQ1, 'C');
	printDQ(DQ1);

	printf("\n front ���� >> ");
	data = deleteFront(DQ1);
	printDQ(DQ1);
	printf("\t���� ������ : %c", data);

	printf("\n rear ���� >> ");
	data = deleteRear(DQ1);
	printDQ(DQ1);
	printf("\t���� ������ : %c", data);

	printf("\n rear���� D>> ");
	insertRear(DQ1, 'D');
	printDQ(DQ1);

	printf("\n front���� E>> ");
	insertFront(DQ1, 'E');
	printDQ(DQ1);

	printf("\n front���� F>> ");
	insertFront(DQ1, 'F');
	printDQ(DQ1);

	data = peekFront(DQ1);
	printf("\n peek Front item : %c \n", data);

	data = peekRear(DQ1);
	printf("peek Rear item : %c \n", data);

	return 0;
}


