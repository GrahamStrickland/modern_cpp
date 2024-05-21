#include <iostream>

double& square_ref(double d)    // Error: returns stale reference
{
    double s= d * d;
    return s;                   // Error: s will be out of scope
}

double* square_ptr(double d)    // Error: returns dangling pointer
{
    double s= d * d;
    return &s;                  // Error: s will be out of scope
}

int main(int argc, char* argv[])
{
    int  i= 5;
    int& j= i;
    j= 4;

    std::cout << "i = " << i << '\n';

    double d= 2.0;
    double s= square_ref(d);
    std::cout << "d = " << d << ", d^2 = " << s << std::endl;

    double d2= 2.0;
    double* s2= square_ptr(d);
    std::cout << "d2 = " << d2 << ", d2^2 = " << *s2 << std::endl;

    return EXIT_SUCCESS;
}

