#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <typeinfo>

#include <fmt/format.h>
#include <fmt/ostream.h>

void print_average(float v1, float v2, int language)
{
    using namespace fmt;
    std::string formats[]= {
        "The average of {v1} and {v2} is {result}.\n",
        "{result:.6f} ist der Durschnitt von {v1} und {v2}.\n",
        "La moyenne de {v1} et {v2} est {result}.\n",
        "El promedio de {v1} y {v2} es {result}.\n",
        "{result} corrisponde alla media di {v1} e {v2}.\n"};
    print(formats[language], "v1"_a= v1, "v2"_a= v2,
            "result"_a= (v1+v2)/2.0f);
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 5; i++)
        print_average(3.5, 7.3, i);

    return EXIT_SUCCESS;
}
