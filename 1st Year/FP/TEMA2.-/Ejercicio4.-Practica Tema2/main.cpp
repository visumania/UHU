#include <iostream>

using namespace std;

int main()

{
    int v1 , v2 , v3 ;
    cout << "Dame un valor ";
    cin >> v1 ;
    cout << "Dame otro valor ";
    cin >> v2 ;
    v3=v1;
    v1=v2;
    v2=v3;
    cout << v1;
    cout << v2;

    return 0;
}
