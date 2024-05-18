#include <iostream>

void vector_add(unsigned size, const double v1[], const double v2[],
                double s[])
{
    for (unsigned i= 0; i < size; ++i)
        s[i]= v1[i] + v2[i];
}

int main(int argc, char* argv[])
{
    double x[]= {2, 3, 4}, y[]= {4, 2, 0}, sum[3];
    vector_add(sizeof x / sizeof x[0], x, y, sum);

    unsigned size = sizeof x / sizeof x[0];
    std::cout << "x + y = [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << x[i] << (i < size - 1 ? ", " : "]");

    std::cout << " + [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << y[i] << (i < size - 1 ? ", " : "]");

    std::cout << " = [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << sum[i] << (i < size - 1 ? ", " : "]");
    std::cout << '\n';

    const int size2= 3;
    double *x2= new double[size2], *y2= new double[size2],
           *sum2= new double[size2];
    for (unsigned i= 0; i < size2; ++i)
        x2[i]= i+2, y2[i]= 4-2*i;
    vector_add(size2, x2, y2, sum2);

    std::cout << "x + y = [";
    for (unsigned i= 0; i < size2; ++i)
        std::cout << x2[i] << (i < size2 - 1 ? ", " : "]");

    std::cout << " + [";
    for (unsigned i= 0; i < size2; ++i)
        std::cout << y2[i] << (i < size2 - 1 ? ", " : "]");

    std::cout << " = [";
    for (unsigned i= 0; i < size2; ++i)
        std::cout << sum2[i] << (i < size2 - 1 ? ", " : "]");
    std::cout << '\n';

    delete[] x2;
    delete[] y2;
    delete[] sum2;

    return EXIT_SUCCESS;
}

