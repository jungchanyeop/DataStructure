#include <stdio.h>
#include "heap.h"

int main() {

	int n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);

	n = heap->heap_size;
	for (int i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete : [%d] ", item);
	}

	return 0;
}