#include <fstream>

int main()
{
    std::ofstream square_file{"squares.txt"};
    for (int i= 0; i < 10; i++)
        square_file << i << "^2 = " << i*i << '\n';
}

