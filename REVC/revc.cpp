#include <iostream>
#include <string>
#include <algorithm>

void reverseComplement(const std::string& strand)
{
    std::string reversedStrand = strand;
    std::reverse(reversedStrand.begin(), reversedStrand.end());

    for (const char nucleotide : reversedStrand)
    {
        if (nucleotide == 'A')
        {
            std::cout << "T";
        }
        else if (nucleotide == 'T')
        {
            std::cout << "A";
        }
        else if (nucleotide == 'G')
        {
            std::cout << "C";
        }
        else if (nucleotide == 'C')
        {
            std::cout << "G";
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::string strand;
    std::cout << "Input: ";
    std::cin >> strand;

    reverseComplement(strand);

    return 0;
}
