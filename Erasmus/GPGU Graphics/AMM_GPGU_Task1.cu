//%%writefile parallel.cu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DATA_TYPE;
#define MAX_INT_VAL 10
#define OK 1

void printMatrix(DATA_TYPE * matrix, int rows, int cols); /* function prototype */
void loadRandMatrix(DATA_TYPE ** matrix, int rows, int cols);

__global__ void multiAB(DATA_TYPE* matrix_A, DATA_TYPE* matrix_B, DATA_TYPE* matrix_C, int nrowA, int ncolA, int ncolB){
  int row = blockIdx.x * blockDim.x + threadIdx.x;
  int col = blockIdx.y * blockDim.y + threadIdx.y;

  if(row<nrowA && col<ncolB){
    DATA_TYPE add = 0;

    for(int k=0 ; k<ncolA ; k++){
      add += matrix_A[row*ncolA+k] * matrix_B[col+k*ncolB];
    }
      
  }
}

int main(void){
	srand((unsigned) time(NULL)); /* random seed */
	double start_time, stop_time; /* for Windows, Linux */
	
	
	DATA_TYPE * A_matrix = NULL; //Pointer to matrix in the host
	DATA_TYPE * B_matrix = NULL; //Pointer to matrix in the host
	DATA_TYPE * C_matrix = NULL; //Pointer to matrix in the host
 
  DATA_TYPE * A_matrix_d = NULL; //Pointer to matrix in the device
	DATA_TYPE * B_matrix_d = NULL; //Pointer to matrix in the device
	DATA_TYPE * C_matrix_d = NULL; //Pointer to matrix in the device
 
	int n, m, p;
	
	/* setting matrices params - n, m and p */
	printf("Enter the number of A rows = "); scanf("%d",&m);
    printf("Enter the number of A cols ( = B rows) = "); scanf("%d",&n);
    printf("Enter the number of B cols = "); scanf("%d",&p);

  int N = m*p;
  size_t size = N*sizeof(DATA_TYPE);
	
	/* create all matrices for C = AxB */
	
	A_matrix = (DATA_TYPE *)malloc(size);
	B_matrix = (DATA_TYPE *)malloc(size);
	C_matrix = (DATA_TYPE *)malloc(size);	
				
	//Load matrix A
  for(int i=0 ; i<m ; i++){
      for(int j=0 ; j<n ; j++){
          A_matrix[i*n+j] = rand() % MAX_INT_VAL;
      }
  }

  //Load matrix B
	for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<p ; j++){
          B_matrix[i*p+j] = rand() % MAX_INT_VAL;
      }
  }

	//For debuging
	//printMatrix(A_matrix, m, n);
	//printMatrix(B_matrix, n, p);
 
  //Alloc space for device copies
  cudaMalloc((void **) &A_matrix_d, size);
  cudaMalloc((void **) &B_matrix_d, size);
  cudaMalloc((void **) &C_matrix_d, size);
 
  //Copy to device
  cudaMemcpy(A_matrix_d, A_matrix, size, cudaMemcpyHostToDevice);
  cudaMemcpy(B_matrix_d, B_matrix, size, cudaMemcpyHostToDevice);

  //Threads per block
  int BLOCK_SIZE = 16;

  //Blocks in each dimension
  int GRID_SIZE = (int)ceil(N/BLOCK_SIZE);

  dim3 grid(GRID_SIZE,GRID_SIZE);
  dim3 threads(BLOCK_SIZE,BLOCK_SIZE);

	start_time = clock();  /* time measurement */
		
	multiAB<<<grid,threads>>>(A_matrix_d,B_matrix_d,C_matrix_d, m,n,p);  
  cudaDeviceSynchronize();
	
	stop_time = clock(); /* time measurement */
	
	cudaMemcpy(C_matrix, C_matrix_d, size, cudaMemcpyDeviceToHost);
	
	//printMatrix(C_matrix, m, p); 
					
	free(A_matrix);
  free(B_matrix);
  free(C_matrix);

  cudaFree(A_matrix_d);
  cudaFree(B_matrix_d);
  cudaFree(C_matrix_d);

	printf("\nElapsed time of matrices multiplication: %f [seconds]\n",
		  (stop_time-start_time)/CLOCKS_PER_SEC);
	
	puts("\nFinished");

	return 0;
}

void printMatrix(DATA_TYPE * matrix, int rows, int cols)
{
	int i, j;
	
	printf("\nPrint matrix:");
	
	for(i=0; i<rows; i++)
	{
		printf("\n");
		for(j=0; j<cols; j++)
		    printf("%3d ", matrix[i*cols+j]); //the same as matrix[i][j] 
	}
	printf("\n");
	return;
}

void loadRandMatrix(DATA_TYPE ** matrix, int rows, int cols)
{
	int i, j;
	
	printf("\nLoad matrix:");
	
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			matrix[i][j] = rand() % MAX_INT_VAL;
	}
	return;
}