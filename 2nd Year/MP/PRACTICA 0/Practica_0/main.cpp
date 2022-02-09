#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Complejo.h"

using namespace std;


int main()
{
    Complejo a(2,3) , b(1,1) , c(0,0);
    const Complejo d(3,4);

    cout << "La parte real vale " << a.getr() << endl;
    cout << "La parte imaginaria vale " << a.geti() << endl ;

    a.ver();
    cout << "\n\n";
    a.set(-4,8);
    a.ver();
    cout << "\n\n";

    a.set();
    a.ver();
    cout << "\n\n";

    c=a+b;
    c.ver(); cout << "\n\n";
    c=c+2;
    c.ver(); cout << "\n\n";

    c=-b;
    c.ver(); cout << "\n\n";

    c=2+c;
    c.ver(); cout << "\n\n";

    c=c+d;
    c=d+c;
    c.ver(); cout << "\n\n";

    cout << c << endl;

    c++;

    cout << "c incrementado vale " ; c.ver() ; cout << endl;

    cout << "d vale " ; d.ver(); cout << endl;
    cout << "c vale " ; c.ver(); cout << endl;

    ++c;

    cout << "incrementado c vale " ; c.ver() ; cout << endl;

    cout << "D VALE " << d << endl;
    cout << "C VALE " << c << endl;


    return 0;
}
