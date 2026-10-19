// #include <iostream>
// #include <fstream>
// #include <string>



// int main(int argc, char** argv) {
    //     std::ifstream input("sampleData.fasta");
    //     std::string line, id, dna_sequence;
    //     double highestScore = 0.0;
//     std::string highestScoreLabel;

//     while (std::getline(input, line)) 
//     {
//         if (line.empty()) 
//             continue;
        
//         if (line[0] == '>') 
//         {
//             if (!id.empty()) 
//             {
//                 double score = calculateScore(dna_sequence);
//                 if(score > highestScore)
//                 {
//                     highestScore = score;
//                     highestScoreLabel = id;
//                 }
//                 else
//                 {
//                     continue;
//                 }
//                 std::cout << id << " : " << dna_sequence << "\n";
//             }
//             id = line.substr(1);
//             dna_sequence.clear();
//         } 
//         else 
//         {
    //             dna_sequence += line;
    //         }
//     }
//     if (!id.empty()) 
//     {
    //         std::cout << id << " : " << dna_sequence << "\n";
//     }

//     std::cout << highestScoreLabel << std::endl;
//     std::cout << highestScore << std::endl;

//     return 0;
// }   

#include <fstream>
#include <string>
#include <functional>
#include <iostream>
#include <iomanip>

double calculateScore(const std::string& dna_sequence)
{
    int GC_Count = 0;
    for(const auto& base : dna_sequence)
    {
        if(base == 'G' || base == 'C')
        {
            GC_Count++;
        }
    }
    return 100 * (GC_Count / double(dna_sequence.length()));
}

void readFasta(const std::string& path, std::function<void(const std::string& id, const std::string& seq)> fn) 
{
    std::ifstream in(path);
    std::string line, id, seq;

    while (std::getline(in, line)) 
    {
        if (line.empty()) 
            continue;

        if (line[0] == '>') 
        {
            if (!id.empty()) 
                fn(id, seq);   // flush previous record
            id = line.substr(1);
            seq.clear();
        } 
        else 
        {
            seq += line;
        }
    }
    if (!id.empty()) 
        fn(id, seq);           // flush last record
}

int main(int argc, char** argv) 
{
    double highestScore = 0.0;
    std::string highestScoreLabel;

    readFasta(argv[1], [&](const std::string& id, const std::string& seq) 
    {
        // std::cout << id << "  " << seq << "\n";

        double score = calculateScore(seq);
        if(score > highestScore)
        {
            highestScore = score;
            highestScoreLabel = id;
        }
    });

    std::cout << std::fixed << std::setprecision(6);

    std::cout << highestScoreLabel << std::endl;
    std::cout << highestScore << std::endl;

}