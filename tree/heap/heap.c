#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

heapType* createHeap(){
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2])) {  // ��Ʈ�� �������� �ʾҰ�, item�� �θ𺸴� ũ�ٸ�
		h->heap[i] = h->heap[i / 2];  // �θ� ���� �ڽ� �ڸ��� ������ �� �ڸ��� ����
		i /= 2;  // �ε����� �θ� ��ġ�� �Űܼ� �񱳸� �����
	}
	h->heap[i] = item;
}

int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1];                 // ������ ��Ʈ ���(�ִ밪)�� item�� ����
	temp = h->heap[h->heap_size];      // ������ ��� ���� temp�� ���� (��Ʈ�� �ø� �ĺ�)
	h->heap_size = h->heap_size - 1;   // ��� �ϳ��� �����ϱ� ������ ũ�⸦ ����

	parent = 1;                        
	child = 2;                         // ��Ʈ�� ���� �ڽ� �ε���

	while ((child <= h->heap_size)) {
		// STEP 1: ����/������ �ڽ� �� �� ū �ڽ��� ����
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;  // ������ �ڽ��� �� ũ�� ������ �ڽ��� ����

		// STEP 2: temp�� �ڽ� �� �� ū �� ��
		if (temp >= h->heap[child])
			break;  // temp�� �ڽĺ��� ũ�ų� ������ �ڸ� Ȯ�� �� break
		else {
			h->heap[parent] = h->heap[child];  // �� ū �ڽ��� �θ� �ڸ��� �ø�
			parent = child;                    // ������ ��ġ ����
			child = child * 2;                 // ���� �ڽ� ��ġ ��� (���� �ڽ�)
		}
	}

	h->heap[parent] = temp;
	return item;
}

void printHeap(heapType* h){
	printf("Heap : ");
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}