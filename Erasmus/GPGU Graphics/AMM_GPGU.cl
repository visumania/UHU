/*
I have not compiled the program, because as I mentioned earlier,
 I do not have a computer where opencl can work, nor do I 
 have anyone who can borrow it to me. I have followed all the notes 
 that you have uploaded to moodle for the realization of this code.
*/

#define BLOCK_SIZE 16
#define AS(i, j) As[j + i * BLOCK_SIZE]
#define BS(i, j) Bs[j + i * BLOCK_SIZE]

__kernel void
matrixMul( __global float* C, __global float* A, __global float* B, __local float* As, __local float* Bs, int uiWA, int uiWB)
{
    // Block index
    int bx = get_group_id(0); //2D Thread ID x
    int by = get_group_id(1); //2D Thread ID y

    // Thread index
    int tx = get_local_id(0); //2D local ID x
    int ty = get_local_id(1); //2D local ID y

    // Index of the first sub-matrix of A processed by the block
    int aBegin = uiWA * BLOCK_SIZE * by;

    // Index of the last sub-matrix of A processed by the block
    int aEnd   = aBegin + uiWA - 1;

    // Step size used to iterate through the sub-matrices of A
    int aStep  = BLOCK_SIZE;

    // Index of the first sub-matrix of B processed by the block
    int bBegin = BLOCK_SIZE * bx;

    // Step size used to iterate through the sub-matrices of B
    int bStep  = BLOCK_SIZE * uiWB;

    // Csub is used to store the element of the block sub-matrix that is computed by the thread
    float Csub = 0.0f;

    // Loop over all the sub-matrices of A and B required to compute the block sub-matrix
    for (int a = aBegin, b = bBegin;
             a <= aEnd;
             a += aStep, b += bStep) {

        // Load the matrices from device memory to shared memory; each thread loads one element of each matrix
        AS(ty, tx) = A[a + uiWA * ty + tx];
        BS(ty, tx) = B[b + uiWB * ty + tx];
	
        // Synchronize to make sure the matrices are loaded
        barrier(CLK_LOCAL_MEM_FENCE);

        // Multiply the two matrices together; each thread computes one element of the block sub-matrix        
        for (int k = 0; k < BLOCK_SIZE; ++k)
            Csub += AS(ty, k) * BS(k, tx);

        // Synchronize to make sure that the preceding computation is done before loading two new sub-matrices of A and B in the next iteration
        barrier(CLK_LOCAL_MEM_FENCE);
    }

    int c = wB ∗ BLOCKSIZE ∗ by + BLOCKSIZE ∗ bx;
    C[c + wB ∗ ty + tx] = Csub; // write to global memory

}