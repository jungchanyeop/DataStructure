#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"

int isStackEmpty(){
	if (top == NULL)
		return 1;
	else
		return 0;
}

void push(element item){
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	
	newNode->data = item;
	newNode->link = top;
	top = newNode;
}

element pop(){
	element item;
	stackNode* temp = top;
	if (isStackEmpty()) {
		printf("\n 스택이 비어있음");
		return 0;
	}
	else
	{
		item = top->data;
		top = top->link;
		free(temp);
		return item;
	}
}

element peek(){
	if (isStackEmpty()) {
		printf("\n 스택이 비어있음");
		return 0;
	}
	else
		return top->data;
}

void printStack(){
	stackNode* p = top;
	printf("\n STACK [");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}