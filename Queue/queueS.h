#pragma once
#define Q_SIZE 4

typedef char element;

typedef struct {
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue();
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQeue(QueueType* Q);
element peekQ(QueueType* Q);
void printQ(QueueType* Q);