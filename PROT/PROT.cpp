#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

std::string ProteinEncode(const std::string& RNAString) {
  std::unordered_map<std::string, std::string> CodonTable =
  { {"UUU", "F"},
    {"CUU", "L"},
    {"AUU", "I"},
    {"GUU", "V"},
    {"UUC", "F"},
    {"CUC", "L"},
    {"AUC", "I"},
    {"GUC", "V"},
    {"UUA", "L"},
    {"CUA", "L"},
    {"AUA", "I"},
    {"GUA", "V"},
    {"UUG", "L"},
    {"CUG", "L"},
    {"AUG", "M"},
    {"GUG", "V"},
    {"UCU", "S"},
    {"CCU", "P"},
    {"ACU", "T"},
    {"GCU", "A"},
    {"UCC", "S"},
    {"CCC", "P"},
    {"ACC", "T"},
    {"GCC", "A"},
    {"UCA", "S"},
    {"CCA", "P"},
    {"ACA", "T"},
    {"GCA", "A"},
    {"UCG", "S"},
    {"CCG", "P"},
    {"ACG", "T"},
    {"GCG", "A"},
    {"UAU", "Y"},
    {"CAU", "H"},
    {"AAU", "N"},
    {"GAU", "D"},
    {"UAC", "Y"},
    {"CAC", "H"},
    {"AAC", "N"},
    {"GAC", "D"},
    {"UAA", "Stop"},
    {"CAA", "Q"},
    {"AAA", "K"},
    {"GAA", "E"},
    {"UAG", "Stop"},
    {"CAG", "Q"},
    {"AAG", "K"},
    {"GAG", "E"},
    {"UGU", "C"},
    {"CGU", "R"},
    {"AGU", "S"},
    {"GGU", "G"},
    {"UGC", "C"},
    {"CGC", "R"},
    {"AGC", "S"},
    {"GGC", "G"},
    {"UGA", "Stop"},
    {"CGA", "R"},
    {"AGA", "R"},
    {"GGA", "G"},
    {"UGG", "W"},
    {"CGG", "R"},
    {"AGG", "R"},
    {"GGG", "G"} };

    std::string protein = "";

    for(int i = 0; i <= RNAString.length() - 3; i+=3)
    {
        std::string codon = RNAString.substr(i, 3);
        if(!(CodonTable[codon] == "Stop"))
        {
            protein += CodonTable[codon];
        }
        else
        {
            return protein;
        }
    }
    return protein;
}

int main () {
    std::string line;
    std::ifstream myfile ("./rosalind_prot.txt");
    int lineNumber  = 1;
    std::string RNAString;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(lineNumber == 1)
            {
                RNAString = line;
                lineNumber++;
            }
        }
        myfile.close();
        std::cout << ProteinEncode(RNAString) << std::endl;
    }

    else std::cout << "Unable to open file"; 

    return 0;
}