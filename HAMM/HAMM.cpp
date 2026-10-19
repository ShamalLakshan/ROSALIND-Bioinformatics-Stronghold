#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int HammingDistance(std::string p, std::string q)
{
    int distance = 0;
    for(int i = 0; i <= p.length(); ++i)
    {
        if(p[i] != q[i])
        {
            distance += 1;
        }
    }
    return distance;
}

int main () {
    std::string line;
    std::ifstream myfile ("./rosalind_hamm.txt");
    int lineNumber  = 1;
    std::string p;
    std::string q;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(lineNumber == 1)
            {
                p = line;
                lineNumber++;
            }
            else if(lineNumber == 2)
            {
                q = line;
                lineNumber++;
            }
        }
        myfile.close();
        std::cout << HammingDistance(p, q) << std::endl;
    }

    else std::cout << "Unable to open file"; 

    return 0;
}