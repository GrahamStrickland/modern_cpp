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

    return EXIT_SUCCESS;
}

