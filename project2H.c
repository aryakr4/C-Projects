#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

int *AllocateArray(int N){
	int *A = (int*) malloc(N *sizeof(int));
	for(int i=0; i < N; i++){
    		A[i] = rand() % (10*N);
  	}
    	return A;
}

int compar(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );

}

void SortArray(int *A, int N)
{
	qsort(A, N, sizeof(int), compar);
}



void DeallocateArray(int *A)
{
  free(A);
}
int main()
{
int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

for (int i = 0 ; i < 8 ; i++)
{
double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
struct timeval startTime;
struct timeval endTime;

	gettimeofday(&startTime, NULL); 
        int *A = AllocateArray(sizes[i]); 
        gettimeofday(&endTime, NULL); 

        alloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                     (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

	gettimeofday(&startTime, NULL); 
        SortArray(A, sizes[i]); 
        gettimeofday(&endTime, NULL); 

        sort_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                     (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

	gettimeofday(&startTime, NULL); 
        DeallocateArray(A); 
        gettimeofday(&endTime, NULL); 

        dealloc_time = (double)(endTime.tv_sec - startTime.tv_sec) + 
                     (double)(endTime.tv_usec - startTime.tv_usec) / 1000000.;

  
  printf("Timings for array of size %d\n", sizes[i]);
printf("\tTime for allocation is %g, time per element = %g\n", alloc_time,
alloc_time/sizes[i]);
printf("\tTime for sort_time is %g, time per element = %g\n", sort_time,
sort_time/sizes[i]);
printf("\tTime for deallocation is %g\n", dealloc_time);
}
}
