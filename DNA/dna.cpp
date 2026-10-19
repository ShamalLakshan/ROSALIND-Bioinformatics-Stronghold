#include <iostream>
#include <string>

void countNucleotides(const std::string& strand, int& A, int& C, int& G, int& T)
{
    A = 0;
    C = 0;
    G = 0;
    T = 0;

    for (const char nucleotide : strand)
    {
        if (nucleotide == 'A')
        {
            A = A + 1;
        }
        else if (nucleotide == 'C')
        {
            C = C + 1;
        }
        else if (nucleotide == 'G')
        {
            G = G + 1;
        }
        else if (nucleotide == 'T')
        {
            T = T + 1;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    std::string strand;
    std::cout << "Input: ";
    std::cin >> strand;

    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;

    countNucleotides(strand, A, C, G, T);

    std::cout << A << " " << C << " " << G << " " << T << std::endl;

    return 0;
}
