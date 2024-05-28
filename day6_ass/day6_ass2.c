#include<stdio.h>
#include<pthread.h>

struct array {
	int *arr;
	int size;
};

void bubble_sort(int *arr, int n) {
	int i,j,temp;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
					temp = arr[j];
					arr[j]= arr[j+1];
					arr[j+1] = temp;
					}
					}
					}
					}
					void* thread_func(void *param) {
					struct array *arr_struct = (struct array*) param;
					bubble_sort(arr_struct-> arr, arr_struct->size);
					return NULL;
					}

					int main() {
					int n=10;
					int arr[10] = {64, 25, 12, 22, 11, 34, 90, 78, 56, 1};
					struct array arr_struct = {arr, n};
					pthread_t tid;

					pthread_create(&tid, NULL, thread_func, (void*)&arr_struct);
					pthread_join(tid, NULL);
					printf("Bubble sorted array:");
					for(int i=0; i<n; i++) {
						printf("%d", arr[i]);
					}
					printf("\n");
					return 0;
					}
