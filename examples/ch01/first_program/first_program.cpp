#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	std::cout << "The anser to the Ultimate Question of Life,\n"
			  << "the Universe, and Everything is:"
			  << std::endl << 6 * 7 << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	return 0;
}

