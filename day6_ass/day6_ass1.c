#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 10

void* sort_arr(void *param) {
	int arr[10] = {8,2,5,1,9,3,7,10,4,6};
	
	
	int n=10;
   	int i, j, position, swap, *res;
   	for (i = 0; i < (n - 1); i++) {
      		position = i;
     	 for (j = i + 1; j < n; j++) {
        	 if (arr[position] > arr[j])
           	 position = j;
      	}
      	if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      	}

   	}
  	 for (i = 0; i < n; i++) {
      		printf("%d\t", arr[i]);
	 }

	 res = (int*)malloc(sizeof(int));
	 for(i=0; i<=10;i++) {
		 *res = arr[i];
		 return res;
	 }
	// *res = arr[i];
       	// return res;
 
}

int main() {
	int ret, *result;
	pthread_t t1;

//	int arr[10] = {22,44,11,33,88,99,77,55,35,74};
	ret = pthread_create(&t1, NULL, sort_arr, NULL);
	printf("Main thread waiting for t1 thread...\n");
	pthread_join(t1, (void**)&result);


	//printf("t1 result:: %d\n", *result);

	return 0;
}
