#include <stdio.h>
#include <stdlib.h>
#include "queueC.h"

QueueType* createCQueue(){
	QueueType* cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;

	return cQ;
}

int isCQueueEmpty(QueueType* cQ){
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is Empty! ");
		return 1;
	}
	else
		return 0;
}

int isCQueueFull(QueueType* cQ){
	if ((cQ->rear + 1) % cQ_SIZE == cQ->front) {
		printf(" Circular Queue is Full! ");
		return 1;
	}
	else
		return 0;
}

void enCQueue(QueueType* cQ, element item){
	QueueType* p = (QueueType*)malloc(sizeof(QueueType));

	if (isCQueueFull(cQ))
		return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}

}

element deCQueue(QueueType* cQ){
	if (isCQueueEmpty(cQ))
		return;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

element peekCQ(QueueType* cQ){
	if (isCQueueEmpty(cQ))
		return;
	else
		return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void printCQ(QueueType* cQ){
	int first, last, i;

	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;

	printf("Circular Queue : [");

	i = first;

	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ] ");
}