#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <algorithm>

double calculateWeight(const std::string& proteinString)
{
    double mass = 0.0;
    std::unordered_map<char, double> massTable = {
    {'A',   71.03711},
    {'C',   103.00919},
    {'D',   115.02694},
    {'E',   129.04259},
    {'F',   147.06841},
    {'G',   57.02146},
    {'H',   137.05891},
    {'I',   113.08406},
    {'K',   128.09496},
    {'L',   113.08406},
    {'M',   131.04049},
    {'N',   114.04293},
    {'P',   97.05276},
    {'Q',   128.05858},
    {'R',   156.10111},
    {'S',   87.03203},
    {'T',   101.04768},
    {'V',   99.06841},
    {'W',   186.07931},
    {'Y',   163.06333}
    };

    for(const auto& aminoAcid : proteinString)
    {
        mass += massTable[aminoAcid];
    }

    return mass;
}


int main () {
    std::string line;
    std::ifstream myfile ("./rosalind_prtm.txt");
    int lineNumber  = 1;
    std::string ProteinString;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(lineNumber == 1)
            {
                // clean trailing characters
                std::erase(line, '\r');
                std::erase(line, '\n');
                ProteinString = line;
                lineNumber++;
            }
        }
        myfile.close();
        std::cout << std::fixed << std::setprecision(6) << calculateWeight(ProteinString) << std::endl;
    }

    else std::cout << "Unable to open file"; 

    return 0;
}