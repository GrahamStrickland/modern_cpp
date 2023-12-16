#include <iostream>

void increment(int& x)
{
    x++;
}

int main()
{
    int i= 4;
    increment(i);
    std::cout << "i is " << i << '\n';

    return EXIT_SUCCESS;
}

