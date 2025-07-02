#include <stdio.h>
#include <stdlib.h>
#include "DeQue.h"

DQueType* createDQue(){
	DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
	
	DQ->front = NULL;
	DQ->rear = NULL;

	return DQ;
}

int isDeQEmpty(DQueType* DQ){
	if (DQ->front == NULL)
		return 1;
	else
		return 0;
}

void insertFront(DQueType* DQ, element item){
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));

	newNode->data = item;

	newNode->llink = NULL;
	if (DQ->front == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		DQ->front = newNode;		
	}
}

void insertRear(DQueType* DQ, element item){
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));

	newNode->data = item;

	newNode->rlink = NULL;
	if (DQ->rear == NULL) {
		DQ->rear = newNode;
		DQ->front = newNode;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
	

}

element deleteFront(DQueType* DQ){
	DQNode* temp = DQ->front;
	element item;

	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is Empty! \n");
		return 0;
	}
	else {
		item = temp->data;
		if (DQ->front == DQ->rear) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}		
		free(temp);
		return item;
		
	}
	
}

element deleteRear(DQueType* DQ){
	DQNode* temp = DQ->rear;
	element item;

	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is Empty! \n");
		return 0;
	}
	else {
		item = temp->data;
		if (DQ->front == DQ->rear) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(temp);
		
		return item;
	}
}

element peekFront(DQueType* DQ){
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is Empty! \n");
		return;
	}

	return DQ->front->data;
}

element peekRear(DQueType* DQ){
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is Empty! \n");
		return;
	}
	else
		return DQ->rear->data;
}

void printDQ(DQueType* DQ){
	DQNode* temp = DQ->front;

	printf("Deque : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ] ");
}