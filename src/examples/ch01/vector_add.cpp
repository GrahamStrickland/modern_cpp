#include <iostream>

void vector_add(unsigned size, const double v1[], const double v2[],
                double s[])
{
    for (unsigned i= 0; i < size; ++i)
        s[i]= v1[i] + v2[i];
}

int main(int argc, char* argv[])
{
    unsigned size = 5;
    double v1[] = {1.0, 2.0, 3.0, 4.0, 5.0},
           v2[] = {-1.0, -1.1, -1.2, -1.3, -1.4},
           s[size];

    vector_add(size, v1, v2, s);

    std::cout << "v1 + v2 = [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << v1[i] << (i != size - 1 ? ", " : "]");

    std::cout << " + [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << v2[i] << (i != size - 1 ? ", " : "]");

    std::cout << " = [";
    for (unsigned i= 0; i < size; ++i)
        std::cout << s[i] << (i != size - 1 ? ", " : "]");
    std::cout << '\n';

    return EXIT_SUCCESS;
}

