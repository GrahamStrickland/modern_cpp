#include <filesystem>
#include <iostream>

int main (int argc, char* argv[])
{
    namespace fs = std::filesystem;
    for (auto & p : fs::directory_iterator("."))
        if (is_regular_file(p))
            std::cout << p << " is a regular file.\n";  // Error in Visual Studio
        else if (is_directory(p))
            std::cout << p << " is a directory.\n";
        else
            std::cout << p << " is neither a regular file nor a directory.\n";

    return EXIT_SUCCESS;
}

