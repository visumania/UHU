#include <iostream>
#include <omp.h>
#include <cmath>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

bool prime(int n)
{
    bool isPrime = true;
    int i = 2;

    while(i<=ceil(sqrt(n)) && isPrime)
    {
        if(n%i == 0)
            isPrime=false;
        else
            i++;
    }

    if(isPrime || n==2)
        return true;

    return false;
}

int main()
{
    int N;
    int nPrimes = 0;

    do
    {
        cout << "Insert a number >=2: ";
        cin >> N;

        if(N<2)
        {
            cout << "Error: Number have to be >=2" << endl;
            system("pause");
            system("cls");
        }
    }while(N<2);

    #pragma omp parallel for num_threads(6) schedule(dynamic,1)
    for(int i=2 ; i<=N ; i++)
    {
        if(prime(i))
            nPrimes++;
    }

    cout << "Number of primes between 2 and " << N << ": " << nPrimes << endl;

    return 0;
}
