#include <iostream>
#include <vector>
#include <numeric>

void printVector(const std::vector<int>& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i + 1 < vec.size())
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int sumVector(const std::vector<int>& vec)
{
    int total = 0;
    for (const int val : vec)
    {
        total += val;
    }
    return total;
}

void calculateRabbits(const int n, const int k, std::vector<int>& no_of_rabbits)
{
    int count = 1;
    int i1 = 0;
    int i2 = 1;

    while (count <= n)
    {
        if (count < 3)
        {
            no_of_rabbits.push_back(1); // [1, 1]
        }
        else
        {
            const int f1 = no_of_rabbits[i1];
            const int f2 = no_of_rabbits[i2];
            int fn = 0;
            if (i2 < 2)
            {
                fn = f1 + f2 + k - 1;
            }
            else
            {
                fn = f1 + f2;
            }
            no_of_rabbits.push_back(fn);
            i1 = i1 + 1;
            i2 = i2 + 1;
        }
        count = count + 1;
    }
}

int main()
{
    int n = 0;
    int k = 0;
    std::cout << "Enter number of months(n): ";
    std::cin >> n;
    std::cout << "Enter number of pairs produced(k): ";
    std::cin >> k;

    std::vector<int> no_of_rabbits;
    calculateRabbits(n, k, no_of_rabbits);

    printVector(no_of_rabbits);
    std::cout << "Number of rabbit pairs at " << n << " month: " << (sumVector(no_of_rabbits) - 1) << std::endl;

    return 0;
}
