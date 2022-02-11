#include <iostream>
#include <omp.h>


using namespace std;

int get_task_size(int a, int b)
{
    return a+b;
}

int count_partitions(int n , int m)
{
    if(n<=1 || m==1)
        return 1;

    int count = 0;
    const int Threshold = 2<<5;

    for(int k = min(n,m) ; k>=1 ; k--)
    {
        int a = n-k;
        int b = min(k,m);
        int size = get_task_size(a,b);

        #pragma omp task shared(count) if(size>Threshold)
        {
            count += count_partitions(a ,b);
        }
    }

    #pragma omp taskwait

    return count;
}

int main()
{
    auto start_time = omp_get_wtime();

    //The right answer for 100 is 190569292

    cout << "Parallel execution: " << endl;

    #pragma omp parallel
    {
        #pragma omp single
        cout << count_partitions(100,100) << endl;
    }

    auto calc_time = omp_get_wtime() - start_time;

    cout << "Calc time: " << calc_time << " sec." << endl;

    cout << endl << "Sequential execution:" << endl;

    start_time = omp_get_wtime();

    cout << count_partitions(100,100) << endl;

    calc_time = omp_get_wtime()-start_time;

    cout << "Calc time: " << calc_time << " sec." << endl;

    return 0;

    //I have not add the #pragma omp atomic because the execution was slower than without it
}
