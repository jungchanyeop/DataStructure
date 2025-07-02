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
	while ((i != 1) && (item > h->heap[i / 2])) {  // 루트에 도달하지 않았고, item이 부모보다 크다면
		h->heap[i] = h->heap[i / 2];  // 부모 값을 자식 자리로 내려서 빈 자리를 만듦
		i /= 2;  // 인덱스를 부모 위치로 옮겨서 비교를 계속함
	}
	h->heap[i] = item;
}

int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1];                 // 삭제할 루트 노드(최대값)를 item에 저장
	temp = h->heap[h->heap_size];      // 마지막 노드 값을 temp에 저장 (루트에 올릴 후보)
	h->heap_size = h->heap_size - 1;   // 노드 하나를 삭제하기 때문에 크기를 조정

	parent = 1;                        
	child = 2;                         // 루트의 왼쪽 자식 인덱스

	while ((child <= h->heap_size)) {
		// STEP 1: 왼쪽/오른쪽 자식 중 더 큰 자식을 선택
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;  // 오른쪽 자식이 더 크면 오른쪽 자식을 선택

		// STEP 2: temp와 자식 중 더 큰 값 비교
		if (temp >= h->heap[child])
			break;  // temp가 자식보다 크거나 같으면 자리 확정 → break
		else {
			h->heap[parent] = h->heap[child];  // 더 큰 자식을 부모 자리에 올림
			parent = child;                    // 내려간 위치 갱신
			child = child * 2;                 // 다음 자식 위치 계산 (왼쪽 자식)
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