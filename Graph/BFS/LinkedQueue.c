#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

LQueueType* createLinkedQueue(){
	LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}

int isLQEmpty(LQueueType* LQ){
	if (LQ->front == NULL) {
		printf(" Linked Queue is Empty! ");
		return 1;
	}
	else
		return 0;
}

void enLQueue(LQueueType* LQ, element item){
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deLQueue(LQueueType* LQ) {
	QNode* temp = LQ->front;
	element item;
	if (isLQEmpty(LQ))
		return;
	else {
		item = temp->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(temp);
		return item;
	}
}

element peekLQ(LQueueType* LQ){
	if (isLQEmpty(LQ)) {
		return 0;
	}
	else
		return LQ->front->data;
}

void printLQ(LQueueType* LQ){
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3d", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}