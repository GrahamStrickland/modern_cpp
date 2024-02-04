#include <fmt>
#include <iostream>

int main(int argc, char* argv[])
{
    print("Decimal:\t{} {} {:06} {} {:0} {:+} {:d}\n",
            1, 2, 3, 0, 0, 4 , -1);
    print("Hexadecimal:\t{:x} {:x} {:X} {:#x}\n", 5, 10, 10, 6);
    print("Octal:\t\t{:o} {:#o}\n", 10, 10, 4);
    print("Binary:\t\t{:b} {:#b} {:#b}\n", 10, 10, 4);

    return EXIT_SUCCESS;
}

