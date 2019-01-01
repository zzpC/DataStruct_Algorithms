#include <stdio.h>
#include <malloc.h>

int rows[3], columns[3];
int main() {
	void log4MultiArray(int (*arr)[3], int len);
	void log4Array(int *arr, int len);
	void heapAdjust(int *heap, int idx, int len);
	void getMin(int *heap, int *min, int idx);

	int A[3] = {1,2,5}, B[3] = {2,4,7}, C[3][3];
	int heap[4], min[3];
	int i, j, minIdx;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			C[i][j] = A[i] + B[j];
		}
	}
	log4MultiArray(C, 3);
	// 初始化堆
	heap[0] = 0;
	for(i = 0; i < 3; i++) {
		heap[i + 1]	= C[i][0];
		rows[i] = i;
		columns[i] = 0;
	}

	for(i = 0; i < 3; i++) {
		heapAdjust(heap, 1, 4);
		getMin(heap, min, i);
		heap[1] = C[rows[0]][++columns[0]];
	}

	log4Array(min, 4);
}

// 拿到最小值
void getMin(int *heap, int *min, int idx) {
	min[idx] = heap[1];
}

// 堆排序调整
void heapAdjust(int *heap, int idx, int len) {
	void swap(int *a,int *b);
	int parent = heap[idx], j;
	for(j = 2 * idx; j < len; j *= 2) {
		if(j < len && heap[j + 1] < heap[j]) {
			++j;
		}
		if(parent < heap[j]) {
			break;
		}
		heap[idx] = heap[j];
		swap(&rows[idx - 1], &rows[j - 1]);
		swap(&columns[idx - 1], &columns[j - 1]);
		idx = j;
	}
	heap[idx] = parent;
}

void swap(int *a,int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void log4Array(int *arr, int len) {
	int i;
	for(i = 0; i < len; i++) {
		printf("%d\n", *(arr + i));
	}
}

void log4MultiArray(int (*arr)[3], int len) { 
	int i,j;
	for(i = 0; i < len; i++) {
		for(j = 0; j < len; j++) {
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
}
