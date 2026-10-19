#ifndef STRAND_GENERATOR_HPP
#define STRAND_GENERATOR_HPP

#include <string>
#include <vector>
#include <random>

inline std::string generateRandomStrand(const int count, const std::vector<char>& nucleotides = {'A', 'C', 'G', 'T'})
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, nucleotides.size() - 1);

    std::string strand = "";
    for (int i = 0; i < count; ++i)
    {
        const char new_nucleotide = nucleotides[dist(gen)];
        strand = strand + new_nucleotide;
    }
    return strand;
}

#endif // STRAND_GENERATOR_HPP
