#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> patternMatch(std::string& genome, std::string& pattern)
{
    int patternLength = pattern.length();
    std::vector<int> indexes;
    for(int i = 0; i <= genome.length(); i++)
    {
        // Extract patternLength no of characters of genome (starting from index i)
        std::string window = genome.substr(i, patternLength);
        if(window == pattern)
        {
            // needs actual location not array index
            indexes.push_back(i + 1);
        }
        else
        {
            continue;
        }
    }
    return indexes;
}

// reusable print vector function for further use
template <typename T>
void PrintVector(T vec)
{
    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main () {
    std::string line;
    std::ifstream myfile ("./rosalind_subs.txt");
    int lineNumber  = 1;
    std::string genome;
    std::string pattern;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(lineNumber == 1)
            {
                genome = line;
                lineNumber++;
            }
            else if(lineNumber == 2)
            {
                pattern = line;
                lineNumber++;
            }
        }
        myfile.close();
        PrintVector(patternMatch(genome, pattern));
    }

    else std::cout << "Unable to open file"; 

    return 0;
}