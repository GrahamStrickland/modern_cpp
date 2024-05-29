#include <cassert>
#include <iostream>
#include <vector>

std::vector<float> add(const std::vector<float>& v1, const std::vector<float>& v2)
{
    assert(v1.size() == v2.size());
    std::vector<float> s(v1.size());
    for (unsigned i= 0; i < v1.size(); ++i)
        s[i]= v1[i] + v2[i];
    return s;
}

int main(int argc, char* argv[])
{
    std::vector<float> v= {1, 2, 3}, w= {7, 8, 9}, s(3);

    std::cout << "v + w = [";
    for (int i= 0; i < 3; ++i)
        std::cout << v[i] << (i < 2 ? ", " : "] + [");
    for (int i= 0; i < 3; ++i)
        std::cout << w[i] << (i < 2 ? ", " : "] = [");

    s = add(v, w);
    for (int i= 0; i < 3; ++i)
        std::cout << s[i] << (i < 2 ? ", " : "]\n");

    return EXIT_SUCCESS;
}
