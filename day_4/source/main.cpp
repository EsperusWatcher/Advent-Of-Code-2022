#include "../include/include.h"

// the file contains pairs of ranges
// find the amount of ranges that overlap each other

int CheckForNesting(int n1, int n2, int n3, int n4)
{
    if (n1 <= n3 && n2 >= n3)
        return 1;

    if (n3 <= n1 && n4 >= n1)
        return 1;

    return 0;
}

// Format is N1-N2,N3-N4
int TranslateLine(std::string line)
{
    int n1, n2, n3, n4;

    n1 = stoi(line.substr(0, line.find("-")));

    line.erase(0, line.find("-") + 1);

    n2 = stoi(line.substr(0, line.find(",")));

    line.erase(0, line.find(",") + 1);

    n3 = stoi(line.substr(0, line.find("-")));
 
    line.erase(0, line.find("-") + 1);
 
    n4 = stoi(line);


    return CheckForNesting(n1, n2, n3, n4);
}

int main()
{
    std::fstream file_hook;

    file_hook.open("puzzle_input.txt", std::ios::in);

    std::string file_line;

    int total_full_covers = 0;

    do
    {
        getline(file_hook, file_line);

        total_full_covers += TranslateLine(file_line);

    } while (!file_hook.eof());
    
    std::cout << "Total overlaps: " << total_full_covers << "\n";

    return 0;
}