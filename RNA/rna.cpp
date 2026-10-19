#include <iostream>
#include <string>
#include <algorithm>

std::string replace(const std::string& strand, const char oldChar, const char newChar)
{
    std::string rna = strand;
    std::replace(rna.begin(), rna.end(), oldChar, newChar);
    return rna;
}

int main()
{
    std::string strand;
    std::cout << "Input: ";
    std::cin >> strand;

    const std::string rna = replace(strand, 'T', 'U');
    std::cout << rna << std::endl;

    return 0;
}
