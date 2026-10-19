#include "strand_generator.hpp"
#include <iostream>

int main()
{
    int count = 0;
    std::cout << "Count: ";
    std::cin >> count;

    const std::string strand = generateRandomStrand(count);
    std::cout << strand << std::endl;

    return 0;
}
